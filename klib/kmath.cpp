////////////////////////////////////////////////////////////////
//
//	Kernel math functions declarations
//
//	File:	kmath.hpp
//	Date:	07 Oct 2019
//
//	Copyright (c) 2017 - 2019, Igor Baklykov
//	All rights reserved.
//
//


#include <klib/kmath.hpp>


// Kernel library code zone
namespace klib {


#if defined(IGROS_ARCH_i386)

	// Divide 64-bit integer by 32-bit integer
	// Returns 64-bit quotient and 64-bit reminder
	udivmod_t kudivmod(quad_t dividend, dword_t divisor) {

		// Division result
		udivmod_t	res	= {0ULL, dividend};
		// Quotient bit
		quad_t		qbit	= 1ULL;

		// Division by 0
		if (0 == divisor) {
			res.quotient = (1 / divisor);
			res.reminder = 0ULL;
			return res;
		}

		while (0 <= sdword_t(divisor)) {
			divisor <<= 1ULL;
			qbit	<<= 1ULL;
		}

		while (qbit) {
			if (res.reminder >= divisor) {
				res.reminder -= divisor;
				res.quotient |= qbit;
			}
			divisor	>>= 1ULL;
			qbit	>>= 1ULL;
		}

		return res;

	}


        // Divide 64-bit integer by 32-bit integer
	// Returns 64-bit quotient and 64-bit reminder
	divmod_t kdivmod(squad_t dividend, dword_t divisor) {

		// Division result
		divmod_t	res	= {0LL, dividend};
		// Quotient bit
		squad_t		qbit	= 1LL;

		// Division by 0
		if (0 == divisor) {
			res.quotient = (1 / divisor);
			res.reminder = 0LL;
			return res;
		}

		while (0 <= divisor) {
			divisor <<= 1LL;
			qbit	<<= 1LL;
		}

		while (qbit) {
			if (res.reminder >= divisor) {
				res.reminder -= divisor;
				res.quotient |= qbit;
			}
			divisor	>>= 1LL;
			qbit	>>= 1LL;
		}

		return res;

	}


#else

	// Divide 64-bit integer by 32-bit integer
	// Returns 64-bit quotient and 64-bit reminder
	udivmod_t kudivmod(quad_t dividend, dword_t divisor) {

		udivmod_t res = {
			quad_t(dividend / divisor),
			quad_t(dividend % divisor)
		};
		return res;

	}


        // Divide 64-bit integer by 32-bit integer
	// Returns 64-bit quotient and 64-bit reminder
	divmod_t kdivmod(squad_t dividend, sdword_t divisor) {

		divmod_t res = {
			squad_t(dividend / divisor),
			squad_t(dividend % divisor)
		};
		return res;

	}

#endif


}	// namespace klib

