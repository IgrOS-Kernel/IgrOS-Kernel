////////////////////////////////////////////////////////////////
//
//	Long mode low-level preparation operations
//
//	File:	longMode.hpp
//	Date:	30 Jun 2020
//
//	Copyright (c) 2017, Igor Baklykov
//	All rights reserved.
//
//


#pragma	once


#include <types.hpp>


// Arch-dependent code zone
namespace igros::arch {


#ifdef	__cplusplus

	extern "C" {

#endif	// __cplusplus


		// Check if loaded with multiboot loader
		constexpr byte_t checkMultiboot() noexcept;
		// Check CPUID is extended
		constexpr byte_t checkCPUID() noexcept;
		// Check CPUID for long mode existance
		constexpr byte_t checkLongMode() noexcept;

		// Setup page tables
		constexpr void	setupPageTables() noexcept;
		// Enable paging
		constexpr void	enablePaging() noexcept;

		// Perform jum to long mode
		constexpr void	jumpToLongMode() noexcept;


#ifdef	__cplusplus

	}

#endif	// __cplusplus


}	// namespace igros::arch

