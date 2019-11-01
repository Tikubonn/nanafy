#define DEFINE_NANAFY_ARRAY(name, type)\
DEFINE_INIT_NANAFY_ARRAY(name, type)\
DEFINE_SET_NANAFY_ARRAY(name, type)\
DEFINE_GET_NANAFY_ARRAY(name, type)\
DEFINE_NANAFY_ARRAY_LENGTH(name, type)\
DEFINE_CLEAR_NANAFY_ARRAY(name, type)\
DEFINE_COPY_NANAFY_ARRAY(name, type)\
DEFINE_EXTEND_NANAFY_ARRAY(name, type)\
DEFINE_FREE_NANAFY_ARRAY(name, type)

#define DECLARE_NANAFY_ARRAY(name, type)\
DEFINE_NANAFY_ARRAY_TYPE(name, type)\
DECLARE_INIT_NANAFY_ARRAY(name, type)\
DECLARE_SET_NANAFY_ARRAY(name, type)\
DECLARE_GET_NANAFY_ARRAY(name, type)\
DECLARE_NANAFY_ARRAY_LENGTH(name, type)\
DECLARE_CLEAR_NANAFY_ARRAY(name, type)\
DECLARE_COPY_NANAFY_ARRAY(name, type)\
DECLARE_EXTEND_NANAFY_ARRAY(name, type)\
DECLARE_FREE_NANAFY_ARRAY(name, type)
