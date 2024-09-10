#pragma once

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
            m_assignedpath(std::move(path)) {
        Load(path);
    }

    File() = default;

    void Load(std::string path) {
        m_assignedpath = path;
#ifdef ROOT_DIR
#define STR(str) #str
#define STRING(str) STR(str)
        m_fullpath = std::string(STRING(ROOT_DIR)) + std::string(path);
#endif
        if (m_fullpath.empty()) {
            m_fullpath = path;
        }

        m_path = m_fullpath;

        m_name = m_path.filename();
        m_extension = m_path.extension();
        m_filetype = CheckFileType(m_extension);
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

    static E_FileType CheckFileType(const std::string &ext) {
        if (supportedFileType.empty()) {
            supportedFileType["png"] = File_Image;
            supportedFileType["jpg"] = File_Image;

            supportedFileType["ttf"] = File_Font;

            supportedFileType["wav"] = File_Audio;
            supportedFileType["ogg"] = File_Audio;
        }

        auto it = supportedFileType.find(ext);
        if (it == supportedFileType.end()) {
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
    static std::unordered_map<std::string, E_FileType> supportedFileType;
};
} // namespace core