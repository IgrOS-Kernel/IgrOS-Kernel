////////////////////////////////////////////////////////////////
//
//	Boot low-level main setup function
//
//	File:	boot.cpp
//	Date:	20 Jan 2020
//
//	Copyright (c) 2017 - 2020, Igor Baklykov
//	All rights reserved.
//
//


// Common
#include <version.hpp>
#include <multiboot.hpp>
#include <platform.hpp>
#include <flags.hpp>

// Architecture dependent
#include <arch/types.hpp>
#include <arch/gdt.hpp>
#include <arch/idt.hpp>
#include <arch/irq.hpp>
#include <arch/paging.hpp>

// Kernel drivers
#include <drivers/vmem.hpp>
#include <drivers/keyboard.hpp>
#include <drivers/pit.hpp>

// Kernel library
#include <klib/kstring.hpp>
#include <klib/kprint.hpp>

// Kernel memory
#include <mem/mmap.hpp>


// Kernel start and end
extern const byte_t _SECTION_KERNEL_START_;
extern const byte_t _SECTION_KERNEL_END_;


#ifdef	__cplusplus

extern "C" {

#endif	// __cplusplus


	// Kernel main function
	void kmain(const multiboot::info_t* const multiboot, const dword_t magic) noexcept {

		// Init VGA memory
		arch::vmemInit();

		// Write Multiboot magic error message message
		klib::kprintf(u8"IgrOS kernel\r\n");

		// Check multiboot magic
		if (!multiboot::check(magic)) {
			// Write Multiboot magic error message message
			klib::kprintf(	u8"BAD MULTIBOOT MAGIC!!!\r\n"
					u8"\tMAGIC:\t\t0x%x\r\n"
					u8"\tADDRESS:\t0x%p\r\n",
					magic,
					multiboot);
			// Hang CPU
			while (true) {};
		}

		// Write Multiboot info message
		klib::kprintf(	u8"BOOT INFO:\r\n"
				u8"\tMAGIC:\t\t0x%x\r\n"
				u8"\tADDRESS:\t0x%p\r\n"
				u8"\tCommands:\t%s\r\n"
				u8"\tLoader:\t\t%s\r\n",
				magic,
				multiboot,
				multiboot->commandLine(),
				multiboot->loaderName());

		// Dump memory info
		multiboot->dumpMemInfo();
		// Dump multiboot memory map
		multiboot->dumpMemMap();

		klib::kprintf(	u8"KERNEL INFO:\r\n"
				u8"Arch:\t\t%s\r\n"
				u8"Start addr:\t0x%p\r\n"
				u8"End addr:\t0x%p\r\n"
				u8"Size:\t\t%d Kb.\r\n"
				u8"Build:\t\t" __DATE__ u8", " __TIME__ u8"\r\n"
				u8"Version:\tv%d.%d.%d [%s]\r\n"
				u8"Author:\t\tIgor Baklykov (c) %d - %d\r\n",
				(IGROS_ARCH),
				&_SECTION_KERNEL_START_,
				&_SECTION_KERNEL_END_,
				dword_t(&_SECTION_KERNEL_END_ - &_SECTION_KERNEL_START_) >> 10,
				IGROS_VERSION_MAJOR,
				IGROS_VERSION_MINOR,
				IGROS_VERSION_BUILD,
				IGROS_VERSION_NAME,
				2017,
				2020);

		// Dump multiboot flags
		//multiboot->dumpFlags();

		// Setup Interrupts Descriptor Table
		arch::idt::init();

		// Init interrupts
		arch::irq::init();

		// Enable interrupts
		arch::irqEnable();

		// Setup Global Descriptors Table
		arch::gdt::init();

		// Setup paging (And identity map first 4MB where kernel physically is)
		arch::paging::init();

		// Setup PIT
		arch::pitSetup();
		// Setup keyboard
		arch::keyboardSetup();

		// Write "Booted successfully" message
		klib::kprintf(u8"\r\nBooted successfully\r\n");

		// Setup physical memory map
		mem::phys::init(reinterpret_cast<multiboot::memoryMapEntry_t*>(multiboot->mmapAddr), multiboot->mmapAddr + multiboot->mmapLength);
		// Allocate one page
		auto pg = mem::phys::alloc();
		reinterpret_cast<dword_t*>(pg)[0] = 45u;
		// Write "Booted successfully" message
		klib::kprintf(u8"Phys. page at:\t0x%p", pg);
		// Free page
		mem::phys::free(pg);
		// Write "Booted successfully" message
		klib::kprintf(u8"Phys. page at:\t0x%p\r\n", pg);

		/*
		klib::kprintf(	u8"Test:\t\t%%c\t= %c\r\n"
				u8"byte_t:\t\t%%hhx\t= 0x%hhx\r\n"
				u8"word_t:\t\t%%hx\t= 0x%hx\r\n"
				u8"dword_t:\t%%x\t= 0x%x\r\n"
				u8"quad_t:\t\t%%llx\t= 0x%llx\r\n",
				u8'5',
				byte_t(0xF0),
				word_t(0xF0F0),
				dword_t(0xF0F0F0F0),
				quad_t(0xF0F0F0F0F0F0F0F0));
		*/

		/*
		auto ptr = reinterpret_cast<byte_t*>(0xA0000);
		for (auto j = 0u; j < 10000000u; j += 4u) {
			ptr[j + 0] = 0x00;
			ptr[j + 1] = 0xFF;
			ptr[j + 2] = 0x00;
		}
		*/

		/*
		// Page mapping test (higher half test)
		auto ptr = reinterpret_cast<word_t*>(0xC00B8006);
		klib::kprintf(	u8"Paging test:\t0x%p = 0x%p\r\n",
				ptr,
				arch::paging::toPhys(pointer_t(ptr)));
		// Rewrite 'IgrOS' text 'O' and 'S' green symbols with white ones
		*ptr = 0x0700 | u8'O';
		++ptr;
		*ptr = 0x0700 | u8'S';
		*/

		/*
		// Page Fault Exception test
		volatile auto ptr2 = reinterpret_cast<word_t*>(0xA0000000);
		*ptr2 = 0x4000;
		*/

		/*
		// Divide by Zero Exception Test
		volatile auto x = 10u;
		volatile auto y = 0u;
		volatile auto z = x / y;
		*/

	}


#ifdef	__cplusplus

}	// extern "C"

#endif	// __cplusplus

