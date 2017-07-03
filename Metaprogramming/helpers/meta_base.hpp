#pragma once
#include <type_traits>

#if __GNUC__ < 6
template <bool B> using bool_constant = std::integral_constant<bool, B>;

template <class...> struct voidify { using type = void; };
template <class... Ts> using void_t = typename voidify<Ts...>::type;
#endif
