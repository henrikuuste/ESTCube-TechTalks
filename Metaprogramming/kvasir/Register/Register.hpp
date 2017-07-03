/**************************************************************************
 * This file contains the Kvasir Register Abstraction DSL (Domain Specific Language)
 * which provide an extra layer between Hardware SFRs
 * (Special Function Registers) and code accessing them.
 * Copyright 2015 Odin Holmes
 * Aditional contribution from Stephan Bökelmann

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
****************************************************************************/
#pragma once
#include "Mpl/Types.hpp"
#include "Mpl/Utility.hpp"
#include "Mpl/Algorithm.hpp"
#include "Types.hpp"
#include "Factories.hpp"
#include "Apply.hpp"


namespace Kvasir {

	namespace Register{
		//this function produces an MPL::List just like MPL::list, however putting
		//one here allows adl to find it without the user having to write out the
		//whole namespace. Making the list take at least one parameter should
		//prevent ambiguity in a case where MPL::list is also an overload candidate
		template<typename T, typename... Ts>
		constexpr brigand::list<T,Ts...> list(T,Ts...){ return brigand::list<T,Ts...>{}; }

		//factory for compile time values
		template<unsigned I>
		constexpr MPL::Value<unsigned, I> value(){
			return MPL::Value<unsigned, I>{};
		}
		template<typename T, T I>
		constexpr MPL::Value<T,I> value(){
			return MPL::Value<T,I>{};
		}

		//bit helpers
		template<typename Address, int Position, typename TFieldType = bool>
		using RWBitLocT = FieldLocation<Address,(1<<Position),ReadWriteAccess,TFieldType>;
		template<typename Address, int Position, typename TFieldType = bool>
		using ROBitLocT = FieldLocation<Address,(1<<Position),ReadOnlyAccess,TFieldType>;
		template<typename Address, int Position, typename TFieldType = bool>
		using WOBitLocT = FieldLocation<Address,(1<<Position),WriteOnlyAccess,TFieldType>;

		//bit field helpers
		template<typename Address, int HighestBit, int LowestBit, typename TFieldType = unsigned>
		using RWFieldLocT = FieldLocation<Address,maskFromRange(HighestBit,LowestBit),ReadWriteAccess,TFieldType>;
		template<typename Address, int HighestBit, int LowestBit, typename TFieldType = unsigned>
		using ROFieldLocT = FieldLocation<Address,maskFromRange(HighestBit,LowestBit),ReadOnlyAccess,TFieldType>;
		template<typename Address, int HighestBit, int LowestBit, typename TFieldType = unsigned>
		using WOFieldLocT = FieldLocation<Address,maskFromRange(HighestBit,LowestBit),WriteOnlyAccess,TFieldType>;

	}
}
