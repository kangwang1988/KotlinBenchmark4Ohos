#ifndef KONAN_LIBTBKMP_H
#define KONAN_LIBTBKMP_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
typedef bool            libTBKMP_KBoolean;
#else
typedef _Bool           libTBKMP_KBoolean;
#endif
typedef unsigned short     libTBKMP_KChar;
typedef signed char        libTBKMP_KByte;
typedef short              libTBKMP_KShort;
typedef int                libTBKMP_KInt;
typedef long long          libTBKMP_KLong;
typedef unsigned char      libTBKMP_KUByte;
typedef unsigned short     libTBKMP_KUShort;
typedef unsigned int       libTBKMP_KUInt;
typedef unsigned long long libTBKMP_KULong;
typedef float              libTBKMP_KFloat;
typedef double             libTBKMP_KDouble;
typedef float __attribute__ ((__vector_size__ (16))) libTBKMP_KVector128;
typedef void*              libTBKMP_KNativePtr;
struct libTBKMP_KType;
typedef struct libTBKMP_KType libTBKMP_KType;

typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Byte;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Short;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Int;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Long;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Float;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Double;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Char;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Boolean;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Unit;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_UByte;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_UShort;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_UInt;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_ULong;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_com_taobao_kmp_Logger;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_com_taobao_kmp_Logger_Companion;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_com_taobao_kmp_Body;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_com_taobao_kmp_nbody;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_com_taobao_kmp_nbody_Companion;
typedef struct {
  libTBKMP_KNativePtr pinned;
} libTBKMP_kref_kotlin_Array;


typedef struct {
  /* Service functions. */
  void (*DisposeStablePointer)(libTBKMP_KNativePtr ptr);
  void (*DisposeString)(const char* string);
  libTBKMP_KBoolean (*IsInstance)(libTBKMP_KNativePtr ref, const libTBKMP_KType* type);
  libTBKMP_kref_kotlin_Byte (*createNullableByte)(libTBKMP_KByte);
  libTBKMP_KByte (*getNonNullValueOfByte)(libTBKMP_kref_kotlin_Byte);
  libTBKMP_kref_kotlin_Short (*createNullableShort)(libTBKMP_KShort);
  libTBKMP_KShort (*getNonNullValueOfShort)(libTBKMP_kref_kotlin_Short);
  libTBKMP_kref_kotlin_Int (*createNullableInt)(libTBKMP_KInt);
  libTBKMP_KInt (*getNonNullValueOfInt)(libTBKMP_kref_kotlin_Int);
  libTBKMP_kref_kotlin_Long (*createNullableLong)(libTBKMP_KLong);
  libTBKMP_KLong (*getNonNullValueOfLong)(libTBKMP_kref_kotlin_Long);
  libTBKMP_kref_kotlin_Float (*createNullableFloat)(libTBKMP_KFloat);
  libTBKMP_KFloat (*getNonNullValueOfFloat)(libTBKMP_kref_kotlin_Float);
  libTBKMP_kref_kotlin_Double (*createNullableDouble)(libTBKMP_KDouble);
  libTBKMP_KDouble (*getNonNullValueOfDouble)(libTBKMP_kref_kotlin_Double);
  libTBKMP_kref_kotlin_Char (*createNullableChar)(libTBKMP_KChar);
  libTBKMP_KChar (*getNonNullValueOfChar)(libTBKMP_kref_kotlin_Char);
  libTBKMP_kref_kotlin_Boolean (*createNullableBoolean)(libTBKMP_KBoolean);
  libTBKMP_KBoolean (*getNonNullValueOfBoolean)(libTBKMP_kref_kotlin_Boolean);
  libTBKMP_kref_kotlin_Unit (*createNullableUnit)(void);
  libTBKMP_kref_kotlin_UByte (*createNullableUByte)(libTBKMP_KUByte);
  libTBKMP_KUByte (*getNonNullValueOfUByte)(libTBKMP_kref_kotlin_UByte);
  libTBKMP_kref_kotlin_UShort (*createNullableUShort)(libTBKMP_KUShort);
  libTBKMP_KUShort (*getNonNullValueOfUShort)(libTBKMP_kref_kotlin_UShort);
  libTBKMP_kref_kotlin_UInt (*createNullableUInt)(libTBKMP_KUInt);
  libTBKMP_KUInt (*getNonNullValueOfUInt)(libTBKMP_kref_kotlin_UInt);
  libTBKMP_kref_kotlin_ULong (*createNullableULong)(libTBKMP_KULong);
  libTBKMP_KULong (*getNonNullValueOfULong)(libTBKMP_kref_kotlin_ULong);

  /* User functions. */
  struct {
    struct {
      struct {
        struct {
          struct {
            struct {
              struct {
                libTBKMP_KType* (*_type)(void);
                libTBKMP_kref_com_taobao_kmp_Logger_Companion (*_instance)();
                void (*info)(libTBKMP_kref_com_taobao_kmp_Logger_Companion thiz, const char* tag, const char* content);
              } Companion;
              libTBKMP_KType* (*_type)(void);
              libTBKMP_kref_com_taobao_kmp_Logger (*Logger)();
            } Logger;
            struct {
              libTBKMP_KType* (*_type)(void);
              libTBKMP_kref_com_taobao_kmp_Body (*Body)(libTBKMP_KDouble x, libTBKMP_KDouble y, libTBKMP_KDouble z, libTBKMP_KDouble vx, libTBKMP_KDouble vy, libTBKMP_KDouble vz, libTBKMP_KDouble mass);
              libTBKMP_KDouble (*get_mass)(libTBKMP_kref_com_taobao_kmp_Body thiz);
              void (*set_mass)(libTBKMP_kref_com_taobao_kmp_Body thiz, libTBKMP_KDouble set);
              libTBKMP_KDouble (*get_vx)(libTBKMP_kref_com_taobao_kmp_Body thiz);
              void (*set_vx)(libTBKMP_kref_com_taobao_kmp_Body thiz, libTBKMP_KDouble set);
              libTBKMP_KDouble (*get_vy)(libTBKMP_kref_com_taobao_kmp_Body thiz);
              void (*set_vy)(libTBKMP_kref_com_taobao_kmp_Body thiz, libTBKMP_KDouble set);
              libTBKMP_KDouble (*get_vz)(libTBKMP_kref_com_taobao_kmp_Body thiz);
              void (*set_vz)(libTBKMP_kref_com_taobao_kmp_Body thiz, libTBKMP_KDouble set);
              libTBKMP_KDouble (*get_x)(libTBKMP_kref_com_taobao_kmp_Body thiz);
              void (*set_x)(libTBKMP_kref_com_taobao_kmp_Body thiz, libTBKMP_KDouble set);
              libTBKMP_KDouble (*get_y)(libTBKMP_kref_com_taobao_kmp_Body thiz);
              void (*set_y)(libTBKMP_kref_com_taobao_kmp_Body thiz, libTBKMP_KDouble set);
              libTBKMP_KDouble (*get_z)(libTBKMP_kref_com_taobao_kmp_Body thiz);
              void (*set_z)(libTBKMP_kref_com_taobao_kmp_Body thiz, libTBKMP_KDouble set);
            } Body;
            struct {
              struct {
                libTBKMP_KType* (*_type)(void);
                libTBKMP_kref_com_taobao_kmp_nbody_Companion (*_instance)();
                libTBKMP_KDouble (*get_DAYS_PER_YEAR)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz);
                void (*set_DAYS_PER_YEAR)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz, libTBKMP_KDouble set);
                libTBKMP_KDouble (*get_PI)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz);
                void (*set_PI)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz, libTBKMP_KDouble set);
                libTBKMP_KDouble (*get_SOLAR_MASS)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz);
                void (*set_SOLAR_MASS)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz, libTBKMP_KDouble set);
                void (*advance)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz, libTBKMP_kref_kotlin_Array bodies, libTBKMP_KDouble dt);
                libTBKMP_KDouble (*energy)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz, libTBKMP_kref_kotlin_Array bodies);
                void (*nbody)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz, libTBKMP_KInt n);
                void (*offsetMomentum)(libTBKMP_kref_com_taobao_kmp_nbody_Companion thiz, libTBKMP_kref_kotlin_Array bodies);
              } Companion;
              libTBKMP_KType* (*_type)(void);
              libTBKMP_kref_com_taobao_kmp_nbody (*nbody)();
            } nbody;
            void (*runNBody)(libTBKMP_KInt n);
            void (*logInfo)(const char* tag, const char* content);
          } kmp;
        } taobao;
      } com;
    } root;
  } kotlin;
} libTBKMP_ExportedSymbols;
extern libTBKMP_ExportedSymbols* libTBKMP_symbols(void);
#ifdef __cplusplus
}  /* extern "C" */
#endif
#endif  /* KONAN_LIBTBKMP_H */
