
# Nanafy

![](https://img.shields.io/badge/License-MIT-green)
![](https://img.shields.io/badge/OS-Windows-blue)
![](https://img.shields.io/badge/CPU-x86%20and%20x64-blue)
![](https://img.shields.io/badge/Compiler-GCC-blue)

Nanafy はオブジェクトファイルの作成を補助してくれるライブラリです。
このライブラリを利用することで、オブジェクトファイルの仕様に精通していなくても、
決められた手続きを行うことで簡単にそれらの作成を行うことができます。

このライブラリは Windows が公開している PE(Portable Executable) ファイルの仕様書を読んだり、
GCC が作成したオブジェクトファイルの中身を読んだりして書かれました。
そのため、このライブラリによって作成されるオブジェクトファイルは他のコンパイラでは利用できない可能性があります。ご留意ください。
また OS 毎にオブジェクトファイルの仕様が異なるようなので Windows 以外には未対応です。

## Usage

下記の簡単な使用例では、終了コードに 0 を返す関数 `main` が定義されたオブジェクトファイルを作成しています。
ソースコードが長すぎるとページを多く占有してしまうため、例外処理は省いています。

```c
#include <nanafy.h>
#include <stdio.h>

#define _MAIN "_main"

static char RETURN_ZERO[] = { 
  0xb8, 0x00, 0x00, 0x00, 0x00,
  0xc3
};

int main (){
  FILE *file = fopen("example.o", "wb");
  nanafy_info nanainfo;
  setup_nanafy_info_for_x86(NANAFY_BIG_ENDIAN, &nanainfo);
  nanafy *nana = make_empty_nana(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo);
  size_t symmain;
  register_nanafy_symbol(_MAIN, sizeof(_MAIN), NANAFY_TEXT_SECTION, nana, &symmain);
  write_nanafy(RETURN_ZERO, sizeof(RETURN_ZERO), NANAFY_TEXT_SECTION, nana);
  {
    size_t offset = 0;
    while (1){
      char buffer[1024];
      size_t readsize;
      read_nanafy_product(buffer, sizeof(buffer), nana, &readsize);
      if (0 < readsize){
        fwrite(buffer, sizeof(char), readsize, file);
        offset += readsize;
      }
      else {
        break;
      }
    }
  }
  free_nanafy(nana);
  fclose(file);
  return 0;
}
```

## API Documentation 

### nanafy_endian

nanafy_endian 型はエンディアンの種類を表します。

| 定数 | 概要 | 
| ---- | ---- | 
| NANAFY_BIG_ENDIAN    | ビッグエンディアン | 
| NANAFY_LITTLE_ENDIAN | リトルエンディアン | 

### nanafy_section 

nanafy_section 型はセクションの種類を表します。

| 定数 | 概要 | 
| ---- | ---- | 
| NANAFY_TEXT_SECTION   | 実行されるコードなどが置かれる領域です。安全性を考慮してこの領域は実行時の書き込みができないようになっています。書き込み可能な領域が必要な場合には NANAFY_DATA_SECTION あるいは NANAFY_BSS_SECTION を利用してください。 | 
| NANAFY_DATA_SECTION   | 初期値を持つデータが置かれる領域です。 | 
| NANAFY_RODATA_SECTION | 初期値を持つ書き込み不可なデータが置かれる領域です。 | 
| NANAFY_BSS_SECTION    | 初期値を持たないデータが置かれる領域です。 | 

### nanafy_status 

nanafy_status 型は関数の実行結果を表します。

| 定数 | 概要 | 
| ---- | ---- | 
| NANAFY_SUCCESS                                         | 関数は成功した。 | 
| NANAFY_ERROR                                           | 関数は失敗し nanafy 構造体がもつデータの整合性が保証できなくなった。この結果が返された場合には後続する nanafy への操作を中止するべきです。 | 
| NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY                   | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_text_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY                   | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_data_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY                 | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_rodata_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_LOCAL_RELOCATION_LIST_MEMORY_NOT_ENOUGH_MEMORY  | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_local_relocation_list_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_TEXT_RELOCATION_LIST_MEMORY_NOT_ENOUGH_MEMORY   | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_text_relocation_list_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_DATA_RELOCATION_LIST_MEMORY_NOT_ENOUGH_MEMORY   | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_data_relocation_list_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_RODATA_RELOCATION_LIST_MEMORY_NOT_ENOUGH_MEMORY | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_rodata_relocation_list_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_SYMBOL_LIST_MEMORY_NOT_ENOUGH_MEMORY            | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_symbol_list_memory 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY           | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_symname_table 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 
| NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY          | 記憶領域の不足によって関数が実行できなかった。この値が返された場合には remap_nanafy_symname_table 関数で十分な大きさを持つ領域を与えなくてはなりません。 | 

### setup_nanafy_info_for_x86

```c
void setup_nanafy_info_for_x86 (nanafy_endian endian, nanafy_info *nanainfo);
```

nanafy_info 構造体を x86 CPU 用に適切に設定します。

第一引数は CPU のエンディアンの種類です。
この情報はアセンブリのオフセット位置を書き換える際などに利用されます。

### setup_nanafy_info_for_x64

```c
void setup_nanafy_info_for_x64 (nanafy_endian endian, nanafy_info *nanainfo);
```

nanafy_info 構造体を x64 CPU 用に適切に設定します。

第一引数は CPU のエンディアンの種類です。
この情報はアセンブリのオフセット位置を書き換える際などに利用されます。

### init_empty_nanafy

```c
void init_empty_nanafy (nanafy_symname_table_hash_func hashfunc, nanafy_info *nanainfo, nanafy *nana);
```

nanafy 構造体を引数を基に初期化します。

第一引数はシンボル名テーブルが検索の際に利用するハッシュ関数のアドレスです。
もし自作の関数を利用しない場合には NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC 関数を利用することができます。

第二引数は CPU 等の環境情報が記録されている nanafy_info 構造体のアドレスです。
この構造体は最終的に nanafy 構造体内部の nanafy_info にコピーされます。
そのためコピー後に引数の情報を書き換えても副作用は発生しません。

### make_empty_nanafy

```c
nanafy *make_empty_nanafy (nanafy_symname_table_hash_func hashfunc, nanafy_info *nanainfo);
```

新しく nanafy 構造体の領域を確保し、確保後に引数を基にその領域を初期化します。
この関数は返り値として初期化された領域を返します。
関数が失敗した場合には NULL が返されます。

第一引数はシンボル名テーブルが検索の際に利用するハッシュ関数のアドレスです。
もし自作の関数を利用しない場合には NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC 関数を利用することができます。

第二引数は CPU 等の環境情報が記録されている nanafy_info 構造体のアドレスです。
この構造体は最終的に nanafy 構造体内部の nanafy_info にコピーされます。
そのためコピー後に引数の情報を書き換えても副作用は発生しません。

この関数が返す領域が不要になった場合には free_nanafy 関数を使用し領域を解放してください。

### remap_nanafy_text_memory, remap_nanafy_data_memory, remap_nanafy_rodata_memory, remap_nanafy_local_relocation_list, remap_nanafy_text_relocation_list, remap_nanafy_data_relocation_list, remap_nanafy_rodata_relocation_list, remap_nanafy_symname_table, remap_nanafy_symbol_list

```c
int remap_nanafy_text_memory (void *sequence, size_t length, nanafy *nana);
int remap_nanafy_data_memory (void *sequence, size_t length, nanafy *nana);
int remap_nanafy_rodata_memory (void *sequence, size_t length, nanafy *nana);
int remap_nanafy_local_relocation_list (nanafy_local_relocation *sequence, size_t length, nanafy *nana);
int remap_nanafy_text_relocation_list (nanafy_relocation *sequence, size_t length, nanafy *nana);
int remap_nanafy_data_relocation_list (nanafy_relocation *sequence, size_t length, nanafy *nana);
int remap_nanafy_rodata_relocation_list (nanafy_relocation *sequence, size_t length, nanafy *nana);
int remap_nanafy_symbol_list (nanafy_symbol *sequence, size_t length, nanafy *nana);
int remap_nanafy_symname_table (void *bufferseq, size_t bufferlen, size_t *arrayseq, size_t arraylen, nanafy *nana);
```

これらの関数は nanafy の各種領域を新しい別の領域にコピーし差し替えます。
この関数は成功した際に 0 を返します。
差し替え先の領域が十分な大きさを持っていない、
あるいはコピー時に何かしらの不具合が発生した場合には 0 以外の値を返します。

### tell_nanafy

```c
size_t tell_nanafy (nanafy_section section, nanafy *nana);
```

### put_nanafy, put_nanafy_manually

```c
int put_nanafy (int byte, nanafy_section section, nanafy *nana);
nanafy_status put_nanafy_manually (int byte, nanafy_section section, nanafy *nana);
```

１バイト分のデータを指示されたセクションに書き込みます。

put_nanafy 関数は make_empty_nanafy 関数が返した領域を引数に受け取ります。
put_nanafy_manually 関数は init_empty_nanafy 関数が初期化した領域を引数に受け取ります。
それぞれ間違った領域を渡した場合の動作は未定義です。

put_nanafy 関数が成功した場合には 0 が返されます。
失敗した場合には 0 以外の値が返されます。

### write_nanafy, write_nanafy_manually

```c
int write_nanafy (void *sequence, size_t size, nanafy_section section, nanafy *nana);
nanafy_status write_nanafy_manually (void *sequence, size_t size, nanafy_section section, nanafy *nana);
```

データの先頭アドレスから数バイト分を指示されたセクションに書き込みます。

write_nanafy 関数は make_empty_nanafy 関数が返した領域を引数に受け取ります。
write_nanafy_manually 関数は init_empty_nanafy 関数が初期化した領域を引数に受け取ります。
それぞれ間違った領域を渡した場合の動作は未定義です。

put_nanafy 関数が成功した場合には 0 が返されます。
失敗した場合には 0 以外の値が返されます。

### allocate_nanafy, allocate_nanafy_manually

```c
int allocate_nanafy (size_t size, nanafy_section section, nanafy *nana);
nanafy_status allocate_nanafy_manually (size_t size, nanafy_section section, nanafy *nana);
```

指示されたバイト数分セクションに 0 を書き込みます。
この関数は初期値が必要ない領域を確保したい場合に有用です。

### align_nanafy, align_nanafy_manually

```c
int align_nanafy (int value, size_t alignment, nanafy_section section, nanafy *nana);
nanafy_status align_nanafy_manually (int value, size_t alignment, nanafy_section section, nanafy *nana);
```

領域の書き込み位置が指定された整数倍になるまで、指定された１バイト分のデータを書き込み続けます。

### register_nanafy_symbol, register_nanafy_symbol_manually

```c
int register_nanafy_symbol (char *name, size_t namesize, nanafy_section section, nanafy *nana, size_t *symidp);
nanafy_status register_nanafy_symbol_manually (char *name, size_t namesize, nanafy_section section, nanafy *nana, size_t *symidp);
```

nanafy のシンボルテーブルに新しくシンボルを登録します。
これらの関数で登録されたシンボルはリンク時に外部のオブジェクトファイルからも参照することができます。

### register_nanafy_private_symbol, register_nanafy_private_symbol_manually

```c
int register_nanafy_private_symbol (char *name, size_t namesize, nanafy_section section, nanafy *nana, size_t *symidp);
nanafy_status register_nanafy_private_symbol_manually (char *name, size_t namesize, nanafy_section section, nanafy *nana, size_t *symidp);
```

nanafy のシンボルテーブルに新しく非公開のシンボルを登録します。

### register_nanafy_external_symbol, register_nanafy_external_symbol_manually

```c
int register_nanafy_external_symbol (char *name, size_t namesize, nanafy_section section, nanafy *nana, size_t *symidp);
nanafy_status register_nanafy_external_symbol_manually (char *name, size_t namesize, nanafy_section section, nanafy *nana, size_t *symidp);
```

nanafy のシンボルテーブルに新しく外部シンボルを登録します。
これらの関数で登録されたシンボルは実体を持たず、`_printf` や `_putchar` などの外部のライブラリで定義されたオブジェクトを表します。

### put_nanafy_offset, put_nanafy_offset_manually

```c
int put_nanafy_offset (nanafy_section section, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana);
nanafy_status put_nanafy_offset_manually (nanafy_section section, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana);
```

指定されたセクションの位置から現在の位置までの相対的なオフセットを書き込みます。

### set_nanafy_offset, set_nanafy_offset_manually

```c
int set_nanafy_offset (nanafy_section section, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana);
nanafy_status set_nanafy_offset_manually (nanafy_section section, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana);
```

指定されたセクションの位置にもう一つの位置までの相対的なオフセットを書き込みます。

### put_nanafy_external_offset, put_nanafy_external_offset_manually

```c
int put_nanafy_external_offset (size_t symid, nanafy_section section, nanafy_section section, size_t size, nanafy *nana);
nanafy_status put_nanafy_external_offset_manually (size_t symid, nanafy_section section, nanafy_section section, size_t size, nanafy *nana);
```

指定されたシンボルセクションの現在位置を関連付けた後、セクションに指定されたサイズ分の領域を確保します。
これらの関数によって書き込まれた領域はリンク時に絶対的なアドレスに書き換えられます。
これらの関数は外部ライブラリに定義されている値のアドレスを取得する際に有用です。

### put_nanafy_external_relative_offset, put_nanafy_external_relative_offset_manually

```c
int put_nanafy_external_relative_offset (size_t symid, nanafy_section section, nanafy_section section, size_t size, nanafy *nana);
nanafy_status put_nanafy_external_relative_offset_manually (size_t symid, nanafy_section section, nanafy_section section, size_t size, nanafy *nana);
```

指定されたシンボルセクションの現在位置を関連付けた後、セクションに指定されたサイズ分の領域を確保します。
これらの関数によって書き込まれた領域はリンク時に相対的なアドレスに書き換えられます。
これらの関数は外部ライブラリに定義されている関数を呼び出す際に有用です。

### sizeof_nanafy_product

```c
size_t sizeof_nanafy_product (nanafy *nana);
```

nanafy から PE(Portable Executable) ファイル形式のデータを作成しそのサイズを返します。

### read_nanafy_product

```c
int read_nanafy_product (void *sequence, size_t size, size_t offset, nanafy *nana, size_t *readsizep);
```

nanafy から PE(Portable Executable) ファイル形式のデータを作成し読み込みます。

関数が成功した場合、この関数は 0 を返します。
失敗した場合には 0 以外の値を返します。

関数が成功した場合、この関数は引数 sequence に書き込まれたデータのバイト数を引数 readsizep に保存します。
読み込めるデータがもう既にない場合、引数 readsizep に保存される値は 0 になります。

## Installation

Nanafy はビルド用に makefile を同梱しています。そのため下記のコマンドからビルドすることができます。

```shell
$ make 
```

Nanafy は簡易的なテストコードが同梱されています。そのため下記のコマンドからテストを実行することができます。

```shell
$ make test
```

## License 

Nanafy は [MIT License](LICENSE) の許諾の下で公開されています。
