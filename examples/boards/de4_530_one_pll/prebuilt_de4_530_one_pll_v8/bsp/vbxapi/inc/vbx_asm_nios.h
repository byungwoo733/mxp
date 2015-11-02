//VBXCOPYRIGHTTAG
/**
 * @file
 * @defgroup VBX_ASM VBX Assembly Macros
 * @brief VBX ASM Macros
 *
 * @ingroup VBXapi
 */
/**@{*/

#ifndef __VBX_ASM_NIOS_H
#define __VBX_ASM_NIOS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __VBX_ASM_OR_SIM_H
#error "This header file should not be included directly. Instead, include \"vbx_asm_or_sim.h\""
#else

#if VBX_ASSEMBLER

#include "vbx_macros.h"

#include "vbx_asm_enc32.h"

// -------------------------------------

// Nios always uses bit 31 as a cache bypass bit
#define VBX_DCACHE_BYPASS_MASK  0x7fffffff
#define VBX_DCACHE_BYPASS_VAL   0x80000000
#define VBX_DCACHE_NOBYPASS_VAL 0x00000000

// Convert a possibly uncached external memory address from the CPU
// to a physical address that the DMA engine can use. (This happens to be
// the same address that the CPU would use for a cached access.)
#define VBX_DMA_ADDR(x,len)	  \
	(( ((uint32_t) (x)) & VBX_DCACHE_BYPASS_MASK) | VBX_DCACHE_NOBYPASS_VAL)

#define VBX_UNCACHED_ADDR(x) \
	(( ((uint32_t) (x)) & VBX_DCACHE_BYPASS_MASK) | VBX_DCACHE_BYPASS_VAL)
#define VBX_CACHED_ADDR(x)   \
	(( ((uint32_t) (x)) & VBX_DCACHE_BYPASS_MASK) | VBX_DCACHE_NOBYPASS_VAL)

// -------------------------------------

#define _VBXASM __asm__ __volatile__

#define VBX_INSTR_QUAD(W0, W1, W2, W3)													\
	VBX_S{																												\
		_VBXASM ( "custom 0, c0, %0, %1" : : "r" (W0), "r" (W1) );	\
		_VBXASM ( "custom 0, c0, %0, %1" : : "r" (W2), "r" (W3) );	\
	}VBX_E
	
#define VBX_INSTR_DOUBLE(W0, W1)																\
	VBX_S{																												\
		_VBXASM ( "custom 0, c0, %0, %1" : : "r" (W0), "r" (W1) );	\
	}VBX_E

#define VBX_INSTR_SINGLE(W0, RETURN_VAR)																\
	VBX_S{																																\
		_VBXASM ( "custom 0, %0, %1, c0" : "=r" (RETURN_VAR) : "r" (W0) : "memory" ); \
	}VBX_E

#define VBX_ASM(MODIFIERS,VMODE,VINSTR,DEST,SRCA,SRCB)									\
	VBX_INSTR_QUAD((((VINSTR) << (VBX_OPCODE_SHIFT)) | (VMODE) | (MODIFIERS)), \
	               (SRCA), (SRCB), (DEST))

#endif // VBX_ASSEMBLER
#endif // __VBX_ASM_OR_SIM_H

#ifdef __cplusplus
}
#endif

#endif // __VBX_ASM_NIOS_H
/**@}*/
