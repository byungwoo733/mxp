//VBXCOPYRIGHTTAG
#ifndef VBW_MTX_XP_H
#define VBW_MTX_XP_H
#ifdef __cplusplus
#include "vbw_mtx_xp_template.hpp"
extern "C" {
#endif

int vbw_mtx_xp_ext_word(vbx_word_t *out, vbx_word_t *in, const int INROWS, const int INCOLS );
int vbw_mtx_xp_ext_uword(vbx_uword_t *out, vbx_uword_t *in, const int INROWS, const int INCOLS );
int vbw_mtx_xp_ext_half(vbx_half_t *out, vbx_half_t *in, const int INROWS, const int INCOLS );
int vbw_mtx_xp_ext_uhalf(vbx_uhalf_t *out, vbx_uhalf_t *in, const int INROWS, const int INCOLS );
int vbw_mtx_xp_ext_byte(vbx_byte_t *out, vbx_byte_t *in, const int INROWS, const int INCOLS );
int vbw_mtx_xp_ext_ubyte(vbx_ubyte_t *out, vbx_ubyte_t *in, const int INROWS, const int INCOLS );

int vbw_mtx_xp_word(vbx_word_t *v_dst,vbx_word_t* v_src, const int INROWS,const int INCOLS);
int vbw_mtx_xp_uword(vbx_uword_t *v_dst,vbx_uword_t* v_src, const int INROWS,const int INCOLS);
int vbw_mtx_xp_half(vbx_half_t *v_dst,vbx_half_t* v_src, const int INROWS,const int INCOLS);
int vbw_mtx_xp_uhalf(vbx_uhalf_t *v_dst,vbx_uhalf_t* v_src, const int INROWS,const int INCOLS);
int vbw_mtx_xp_byte(vbx_byte_t *v_dst,vbx_byte_t* v_src, const int INROWS,const int INCOLS);
int vbw_mtx_xp_ubyte(vbx_ubyte_t *v_dst,vbx_ubyte_t* v_src, const int INROWS,const int INCOLS);
#ifdef __cplusplus
}
#endif
#endif //VBW_MTX_XP_H
