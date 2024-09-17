#pragma once

#include "log.h"
#include <filesystem>
#include <string>
#include <unordered_map>

namespace core {

enum E_FileType {
    File_Image = 0,
    File_Audio,
    File_Font,
    File_Unknown
};

class File {
public:
    File(std::string path) :
            m_assignedpath(path) {
        Load(m_assignedpath);
    }

    File() {};

    void Load(std::string path) {
        m_assignedpath = path;
#ifdef ROOT_DIR
#define STR(str) #str
#define STRING(str) STR(str)
        m_fullpath = std::string(STRING(ROOT_DIR)) + std::string(path);
#endif
        log::out("###################");
        log::out(path);
        log::out(m_fullpath);
        if (m_fullpath.empty()) {
            m_fullpath = path;
        }

        m_path = m_fullpath;

        m_name = m_path.filename();
        m_extension = m_path.extension();
        m_filetype = File::CheckFileType(m_extension);
    }

    const std::string &Name() {
        return m_name;
    }

    const std::string &FullPath() {
        return m_fullpath;
    }

    const std::string &AssignedPath() {
        return m_assignedpath;
    }

    const std::string &Extension() {
        return m_extension;
    }

    const E_FileType &FileType() {
        return m_filetype;
    }

    E_FileType CheckFileType(const std::string &ext) {
        if (File::supportedFileType.empty()) {
            File::supportedFileType["png"] = File_Image;
            File::supportedFileType["jpg"] = File_Image;

            File::supportedFileType["ttf"] = File_Font;

            File::supportedFileType["wav"] = File_Audio;
            File::supportedFileType["ogg"] = File_Audio;
        }

        auto it = File::supportedFileType.find(ext);
        if (it == File::supportedFileType.end()) {
            return File_Unknown;
        }
        return it->second;
    }

private:
    std::string m_name;
    std::string m_fullpath;
    std::string m_assignedpath;
    std::filesystem::path m_path;
    std::string m_extension;
    E_FileType m_filetype;
    std::unordered_map<std::string, E_FileType> supportedFileType;
};
} // namespace core