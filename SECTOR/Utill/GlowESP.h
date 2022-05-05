#pragma once

namespace GlowESPSetting
{
    bool Status = false;
    bool TeamCheck = true;

    float Color[3] = { 255, 255, 255 };
    float Line = 0.7f;
}


void GlowESP()
{
    while (GlowESPSetting::Status)
    {
        if (Addres::LocalPlayer)
        {
            for (int i = 0; i < 31; i++)
            {
                EntityClass Entity = Addres::EntityList[i];

                if (Entity.Valid())
                {
                    if (GlowESPSetting::TeamCheck && Entity.Teammate())
                    {
                        continue;
                    }

                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x8, GlowESPSetting::Color[0]);
                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0xC, GlowESPSetting::Color[1]);
                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x10, GlowESPSetting::Color[2]);
                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x14, GlowESPSetting::Line);

                    Memory::Write<bool>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x28, true);
                }
            }
        }

        Sleep(10);
    }
}