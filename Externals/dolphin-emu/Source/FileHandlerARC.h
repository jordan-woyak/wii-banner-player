// Copyright (C) 2003 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#ifndef _ARC_FILE_H
#define _ARC_FILE_H

#include <string>
#include <vector>

#include "CommonTypes.h"
#include "Filesystem.h"

namespace DiscIO
{

class CARCFile
{
	public:
		CARCFile(std::istream& file);
        CARCFile(const std::string& _rFilename);
		CARCFile(const std::string& _rFilename, u32 offset);
		CARCFile(const u8* _pBuffer, size_t _BufferSize);

		virtual ~CARCFile();

		bool IsInitialized();

		size_t GetFileSize(const std::string& _rFullPath) const;
		size_t GetFileOffset(const std::string& _rFullPath) const;

		size_t ReadFile(const std::string& _rFullPath, u8* _pBuffer, size_t _MaxBufferSize);

		bool ExportFile(const std::string& _rFullPath, const std::string& _rExportFilename);
		bool ExportAllFiles(const std::string& _rFullPath);


	private:

		u8* m_pBuffer;

		bool m_Initialized;

		typedef std::vector<SFileInfo>CFileInfoVector;
		CFileInfoVector m_FileInfoVector;

		bool ParseBuffer();
		bool ParseBuffer(std::istream& file);

		size_t BuildFilenames(const size_t _FirstIndex, const size_t _LastIndex,
			const char* directory, const char* _szNameTable);
		size_t BuildFilenames(const size_t first_index, const size_t last_index,
			std::istream& file, const char* directory = "");

		const SFileInfo* FindFileInfo(std::string _rFullPath) const;
};

} // namespace

#endif

