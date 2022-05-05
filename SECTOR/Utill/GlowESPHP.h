#pragma once

namespace GlowESP_HPSetting
{
    bool Status = false;
    bool TeamCheck = true;

    float Line = 0.7f;
}


void GlowESP_HP()
{
    while (GlowESP_HPSetting::Status)
    {
        if (Addres::LocalPlayer)
        {
            for (int i = 0; i < 31; i++)
            {
                EntityClass Entity = Addres::EntityList[i];

                if (Entity.Valid())
                {
                    if (GlowESP_HPSetting::TeamCheck && Entity.Teammate())
                    {
                        continue;
                    }

                    Color Color = SDK::GetColorFromEntityHP(Entity.Health());

                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x8, Color.R);
                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0xC, Color.G);
                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x10, Color.B);
                    Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x14, GlowESP_HPSetting::Line);

                    Memory::Write<bool>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x28, true);
                }
            }
        }

        Sleep(20);
    }
}