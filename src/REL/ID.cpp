#include "REL/ID.h"

namespace REL
{
	namespace detail
	{
		bool memory_map::open(stl::zwstring a_name, std::size_t a_size)
		{
			close();

			WinAPI::ULARGE_INTEGER bytes;
			bytes.value = a_size;

			_mapping = WinAPI::OpenFileMapping(
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				false,
				a_name.data());
			if (!_mapping) {
				close();
				return false;
			}

			_view = WinAPI::MapViewOfFile(
				_mapping,
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				0,
				0,
				bytes.value);
			if (!_view) {
				close();
				return false;
			}

			return true;
		}

		bool memory_map::create(stl::zwstring a_name, std::size_t a_size)
		{
			close();

			WinAPI::ULARGE_INTEGER bytes;
			bytes.value = a_size;

			_mapping = WinAPI::OpenFileMapping(
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				false,
				a_name.data());
			if (!_mapping) {
				_mapping = WinAPI::CreateFileMapping(
					WinAPI::INVALID_HANDLE_VALUE,
					nullptr,
					WinAPI::PAGE_READWRITE,
					bytes.hi,
					bytes.lo,
					a_name.data());
				if (!_mapping) {
					return false;
				}
			}

			_view = WinAPI::MapViewOfFile(
				_mapping,
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				0,
				0,
				bytes.value);
			if (!_view) {
				return false;
			}

			return true;
		}

		void memory_map::close()
		{
			if (_view) {
				WinAPI::UnmapViewOfFile(static_cast<const void*>(_view));
				_view = nullptr;
			}

			if (_mapping) {
				WinAPI::CloseHandle(_mapping);
				_mapping = nullptr;
			}
		}
	}
}
