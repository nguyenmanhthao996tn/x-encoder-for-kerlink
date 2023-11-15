#ifndef __APP_TYPE_H__
#define __APP_TYPE_H__

typedef enum {
  TYPE_UNKNOWN = 0,
  TYPE_ENCRYPT,
  TYPE_DECRYPT,
  TYPE_PRINT_HELP
} app_type_t;

app_type_t get_app_type(int argc, char *argv[]);

#endif /* __APP_TYPE_H__ */
