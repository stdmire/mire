#pragma once
#include "log.h"
#include <iostream>
#include <sstream>
#include <string>

namespace core {
class Color {
public:
    Color();
    Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a = 255);
    Color(const std::string &hexCode) {
        if (hexCode.empty() || (hexCode[0] != '#' && hexCode.length() != 7 && hexCode.length() != 9)) {
            throw std::invalid_argument("Invalid hex color format");
        }

        std::string hex = (hexCode[0] == '#') ? hexCode.substr(1) : hexCode;

        if (hex.length() != 6 && hex.length() != 8) {
            throw std::invalid_argument("Hex color must be 6 or 8 characters");
        }

        r = stoi(hex.substr(0, 2), nullptr, 16);
        g = stoi(hex.substr(2, 2), nullptr, 16);
        b = stoi(hex.substr(4, 2), nullptr, 16);
        a = (hex.length() == 8) ? stoi(hex.substr(6, 2), nullptr, 16) : 255;
    }

    unsigned int getR() const;
    unsigned int getG() const;
    unsigned int getB() const;
    unsigned int getA() const;

    void setR(unsigned int r);
    void setG(unsigned int g);
    void setB(unsigned int b);
    void setA(unsigned int a);

    void lighten(float factor);
    void darken(float factor);
    std::string toHex() const;

    bool operator==(const Color &other) const;
    bool operator!=(const Color &other) const;
    Color operator+(const Color &other) const;
    Color operator*(float factor) const;

    friend std::ostream &operator<<(std::ostream &os, const Color &color);

private:
    unsigned int r, g, b, a;

    unsigned int
    clamp(unsigned int value, unsigned int min = 0, unsigned int max = 255) const;
};

const inline Color COLOR_Slate50("#F8FAFC");
const inline Color COLOR_Slate100("#f1f5f9");
const inline Color COLOR_Slate200("#e2e8f0");
const inline Color COLOR_Slate300("#cbd5e1");
const inline Color COLOR_Slate400("#94a3b8");
const inline Color COLOR_Slate500("#64748b");
const inline Color COLOR_Slate600("#475569");
const inline Color COLOR_Slate700("#334155");
const inline Color COLOR_Slate800("#1e293b");
const inline Color COLOR_Slate900("#0f172a");
const inline Color COLOR_Slate950("#020617");
const inline Color COLOR_Gray50("#f9fafb");
const inline Color COLOR_Gray100("#f3f4f6");
const inline Color COLOR_Gray200("#e5e7eb");
const inline Color COLOR_Gray300("#d1d5db");
const inline Color COLOR_Gray400("#9ca3af");
const inline Color COLOR_Gray500("#6b7280");
const inline Color COLOR_Gray600("#4b5563");
const inline Color COLOR_Gray700("#374151");
const inline Color COLOR_Gray800("#1f2937");
const inline Color COLOR_Gray900("#111827");
const inline Color COLOR_Gray950("#030712");
const inline Color COLOR_Zinc50("#fafafa");
const inline Color COLOR_Zinc100("#f4f4f5");
const inline Color COLOR_Zinc200("#e4e4e7");
const inline Color COLOR_Zinc300("#d4d4d8");
const inline Color COLOR_Zinc400("#a1a1aa");
const inline Color COLOR_Zinc500("#71717a");
const inline Color COLOR_Zinc600("#52525b");
const inline Color COLOR_Zinc700("#3f3f46");
const inline Color COLOR_Zinc800("#27272a");
const inline Color COLOR_Zinc900("#18181b");
const inline Color COLOR_Zinc950("#09090b");
const inline Color COLOR_Neutral50("#fafafa");
const inline Color COLOR_Neutral100("#f5f5f5");
const inline Color COLOR_Neutral200("#e5e5e5");
const inline Color COLOR_Neutral300("#d4d4d4");
const inline Color COLOR_Neutral400("#a3a3a3");
const inline Color COLOR_Neutral500("#737373");
const inline Color COLOR_Neutral600("#525252");
const inline Color COLOR_Neutral700("#404040");
const inline Color COLOR_Neutral800("#262626");
const inline Color COLOR_Neutral900("#171717");
const inline Color COLOR_Neutral950("#0a0a0a");
const inline Color COLOR_Stone50("#fafaf9");
const inline Color COLOR_Stone100("#f5f5f4");
const inline Color COLOR_Stone200("#e7e5e4");
const inline Color COLOR_Stone300("#d6d3d1");
const inline Color COLOR_Stone400("#a8a29e");
const inline Color COLOR_Stone500("#78716c");
const inline Color COLOR_Stone600("#57534e");
const inline Color COLOR_Stone700("#44403c");
const inline Color COLOR_Stone800("#292524");
const inline Color COLOR_Stone900("#1c1917");
const inline Color COLOR_Stone950("#0c0a09");
const inline Color COLOR_Red50("#fef2f2");
const inline Color COLOR_Red100("#fee2e2");
const inline Color COLOR_Red200("#fecaca");
const inline Color COLOR_Red300("#fca5a5");
const inline Color COLOR_Red400("#f87171");
const inline Color COLOR_Red500("#ef4444");
const inline Color COLOR_Red600("#dc2626");
const inline Color COLOR_Red700("#b91c1c");
const inline Color COLOR_Red800("#991b1b");
const inline Color COLOR_Red900("#7f1d1d");
const inline Color COLOR_Red950("#450a0a");
const inline Color COLOR_Orange50("#fff7ed");
const inline Color COLOR_Orange100("#ffedd5");
const inline Color COLOR_Orange200("#fed7aa");
const inline Color COLOR_Orange300("#fdba74");
const inline Color COLOR_Orange400("#fb923c");
const inline Color COLOR_Orange500("#f97316");
const inline Color COLOR_Orange600("#ea580c");
const inline Color COLOR_Orange700("#c2410c");
const inline Color COLOR_Orange800("#9a3412");
const inline Color COLOR_Orange900("#7c2d12");
const inline Color COLOR_Orange950("#431407");
const inline Color COLOR_Amber50("#fffbeb");
const inline Color COLOR_Amber100("#fef3c7");
const inline Color COLOR_Amber200("#fde68a");
const inline Color COLOR_Amber300("#fcd34d");
const inline Color COLOR_Amber400("#fbbf24");
const inline Color COLOR_Amber500("#f59e0b");
const inline Color COLOR_Amber600("#d97706");
const inline Color COLOR_Amber700("#b45309");
const inline Color COLOR_Amber800("#92400e");
const inline Color COLOR_Amber900("#78350f");
const inline Color COLOR_Amber950("#451a03");
const inline Color COLOR_Yellow50("#fefce8");
const inline Color COLOR_Yellow100("#fef9c3");
const inline Color COLOR_Yellow200("#fef08a");
const inline Color COLOR_Yellow300("#fde047");
const inline Color COLOR_Yellow400("#facc15");
const inline Color COLOR_Yellow500("#eab308");
const inline Color COLOR_Yellow600("#ca8a04");
const inline Color COLOR_Yellow700("#a16207");
const inline Color COLOR_Yellow800("#854d0e");
const inline Color COLOR_Yellow900("#713f12");
const inline Color COLOR_Yellow950("#422006");
const inline Color COLOR_Lime50("#f7fee7");
const inline Color COLOR_Lime100("#ecfccb");
const inline Color COLOR_Lime200("#d9f99d");
const inline Color COLOR_Lime300("#bef264");
const inline Color COLOR_Lime400("#a3e635");
const inline Color COLOR_Lime500("#84cc16");
const inline Color COLOR_Lime600("#65a30d");
const inline Color COLOR_Lime700("#4d7c0f");
const inline Color COLOR_Lime800("#3f6212");
const inline Color COLOR_Lime900("#365314");
const inline Color COLOR_Lime950("#1a2e05");
const inline Color COLOR_Green50("#f0fdf4");
const inline Color COLOR_Green100("#dcfce7");
const inline Color COLOR_Green200("#bbf7d0");
const inline Color COLOR_Green300("#86efac");
const inline Color COLOR_Green400("#4ade80");
const inline Color COLOR_Green500("#22c55e");
const inline Color COLOR_Green600("#16a34a");
const inline Color COLOR_Green700("#15803d");
const inline Color COLOR_Green800("#166534");
const inline Color COLOR_Green900("#14532d");
const inline Color COLOR_Green950("#052e16");
const inline Color COLOR_Emerald50("#ecfdf5");
const inline Color COLOR_Emerald100("#d1fae5");
const inline Color COLOR_Emerald200("#a7f3d0");
const inline Color COLOR_Emerald300("#6ee7b7");
const inline Color COLOR_Emerald400("#34d399");
const inline Color COLOR_Emerald500("#10b981");
const inline Color COLOR_Emerald600("#059669");
const inline Color COLOR_Emerald700("#047857");
const inline Color COLOR_Emerald800("#065f46");
const inline Color COLOR_Emerald900("#064e3b");
const inline Color COLOR_Emerald950("#022c22");
const inline Color COLOR_Teal50("#f0fdfa");
const inline Color COLOR_Teal100("#ccfbf1");
const inline Color COLOR_Teal200("#99f6e4");
const inline Color COLOR_Teal300("#5eead4");
const inline Color COLOR_Teal400("#2dd4bf");
const inline Color COLOR_Teal500("#14b8a6");
const inline Color COLOR_Teal600("#0d9488");
const inline Color COLOR_Teal700("#0f766e");
const inline Color COLOR_Teal800("#115e59");
const inline Color COLOR_Teal900("#134e4a");
const inline Color COLOR_Teal950("#042f2e");
const inline Color COLOR_Cyan50("#ecfeff");
const inline Color COLOR_Cyan100("#cffafe");
const inline Color COLOR_Cyan200("#a5f3fc");
const inline Color COLOR_Cyan300("#67e8f9");
const inline Color COLOR_Cyan400("#22d3ee");
const inline Color COLOR_Cyan500("#06b6d4");
const inline Color COLOR_Cyan600("#0891b2");
const inline Color COLOR_Cyan700("#0e7490");
const inline Color COLOR_Cyan800("#155e75");
const inline Color COLOR_Cyan900("#164e63");
const inline Color COLOR_Cyan950("#083344");
const inline Color COLOR_Sky50("#f0f9ff");
const inline Color COLOR_Sky100("#e0f2fe");
const inline Color COLOR_Sky200("#bae6fd");
const inline Color COLOR_Sky300("#7dd3fc");
const inline Color COLOR_Sky400("#38bdf8");
const inline Color COLOR_Sky500("#0ea5e9");
const inline Color COLOR_Sky600("#0284c7");
const inline Color COLOR_Sky700("#0369a1");
const inline Color COLOR_Sky800("#075985");
const inline Color COLOR_Sky900("#0c4a6e");
const inline Color COLOR_Sky950("#082f49");
const inline Color COLOR_Blue50("#eff6ff");
const inline Color COLOR_Blue100("#dbeafe");
const inline Color COLOR_Blue200("#bfdbfe");
const inline Color COLOR_Blue300("#93c5fd");
const inline Color COLOR_Blue400("#60a5fa");
const inline Color COLOR_Blue500("#3b82f6");
const inline Color COLOR_Blue600("#2563eb");
const inline Color COLOR_Blue700("#1d4ed8");
const inline Color COLOR_Blue800("#1e40af");
const inline Color COLOR_Blue900("#1e3a8a");
const inline Color COLOR_Blue950("#172554");
const inline Color COLOR_Indigo50("#eef2ff");
const inline Color COLOR_Indigo100("#e0e7ff");
const inline Color COLOR_Indigo200("#c7d2fe");
const inline Color COLOR_Indigo300("#a5b4fc");
const inline Color COLOR_Indigo400("#818cf8");
const inline Color COLOR_Indigo500("#6366f1");
const inline Color COLOR_Indigo600("#4f46e5");
const inline Color COLOR_Indigo700("#4338ca");
const inline Color COLOR_Indigo800("#3730a3");
const inline Color COLOR_Indigo900("#312e81");
const inline Color COLOR_Indigo950("#1e1b4b");
const inline Color COLOR_Violet50("#f5f3ff");
const inline Color COLOR_Violet100("#ede9fe");
const inline Color COLOR_Violet200("#ddd6fe");
const inline Color COLOR_Violet300("#c4b5fd");
const inline Color COLOR_Violet400("#a78bfa");
const inline Color COLOR_Violet500("#8b5cf6");
const inline Color COLOR_Violet600("#7c3aed");
const inline Color COLOR_Violet700("#6d28d9");
const inline Color COLOR_Violet800("#5b21b6");
const inline Color COLOR_Violet900("#4c1d95");
const inline Color COLOR_Violet950("#2e1065");
const inline Color COLOR_Purple50("#faf5ff");
const inline Color COLOR_Purple100("#f3e8ff");
const inline Color COLOR_Purple200("#e9d5ff");
const inline Color COLOR_Purple300("#d8b4fe");
const inline Color COLOR_Purple400("#c084fc");
const inline Color COLOR_Purple500("#a855f7");
const inline Color COLOR_Purple600("#9333ea");
const inline Color COLOR_Purple700("#7e22ce");
const inline Color COLOR_Purple800("#6b21a8");
const inline Color COLOR_Purple900("#581c87");
const inline Color COLOR_Purple950("#3b0764");
const inline Color COLOR_Fuchsia50("#fdf4ff");
const inline Color COLOR_Fuchsia100("#fae8ff");
const inline Color COLOR_Fuchsia200("#f5d0fe");
const inline Color COLOR_Fuchsia300("#f0abfc");
const inline Color COLOR_Fuchsia400("#e879f9");
const inline Color COLOR_Fuchsia500("#d946ef");
const inline Color COLOR_Fuchsia600("#c026d3");
const inline Color COLOR_Fuchsia700("#a21caf");
const inline Color COLOR_Fuchsia800("#86198f");
const inline Color COLOR_Fuchsia900("#701a75");
const inline Color COLOR_Fuchsia950("#4a044e");
const inline Color COLOR_Pink50("#fdf2f8");
const inline Color COLOR_Pink100("#fce7f3");
const inline Color COLOR_Pink200("#fbcfe8");
const inline Color COLOR_Pink300("#f9a8d4");
const inline Color COLOR_Pink400("#f472b6");
const inline Color COLOR_Pink500("#ec4899");
const inline Color COLOR_Pink600("#db2777");
const inline Color COLOR_Pink700("#be185d");
const inline Color COLOR_Pink800("#9d174d");
const inline Color COLOR_Pink900("#831843");
const inline Color COLOR_Pink950("#500724");
const inline Color COLOR_Rose50("#fff1f2");
const inline Color COLOR_Rose100("#ffe4e6");
const inline Color COLOR_Rose200("#fecdd3");
const inline Color COLOR_Rose300("#fda4af");
const inline Color COLOR_Rose400("#fb7185");
const inline Color COLOR_Rose500("#f43f5e");
const inline Color COLOR_Rose600("#e11d48");
const inline Color COLOR_Rose700("#be123c");
const inline Color COLOR_Rose800("#9f1239");
const inline Color COLOR_Rose900("#881337");
const inline Color COLOR_Rose950("#4c0519");

} // namespace core