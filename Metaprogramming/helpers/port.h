#pragma once

#ifdef _MSC_VER
#define FORCED_INLINE __forceinline
#define TWIDDLE_THUMBS __asm nop;
#else
#define FORCED_INLINE [[gnu::always_inline]] inline
#define TWIDDLE_THUMBS asm volatile("nop");
#endif
#define INLINE_STATIC FORCED_INLINE static
#define INLINE_CONSTEXPR FORCED_INLINE static constexpr
