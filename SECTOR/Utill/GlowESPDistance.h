#pragma once

namespace GlowESP_DistanceSetting
{
    bool Status = false;
    bool TeamCheck = true;

    int Distance = 500;
    float Color[3] = { 255, 255, 255 };
    float Line = 0.7f;
}


void GlowESP_Distance()
{
    while (GlowESP_DistanceSetting::Status)
    {
        if (Addres::LocalPlayer)
        {
            for (int i = 0; i < 31; i++)
            {
                EntityClass Entity = Addres::EntityList[i];

                if (Entity.Valid())
                {
                    if (GlowESP_DistanceSetting::TeamCheck && Entity.Teammate())
                    {
                        continue;
                    }
                    
                    EntityClass LocalPlayer = Addres::LocalPlayer;

                    if (Entity.Distance(LocalPlayer.OriginPos(), Entity.OriginPos()) < GlowESP_DistanceSetting::Distance)
                    {
                        Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x8, GlowESP_DistanceSetting::Color[0]);
                        Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0xC, GlowESP_DistanceSetting::Color[1]);
                        Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x10, GlowESP_DistanceSetting::Color[2]);
                        Memory::Write<float>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x14, GlowESP_DistanceSetting::Line);

                        Memory::Write<bool>(Addres::GlowManager + Entity.GlowIndex() * 0x38 + 0x28, true);
                    }
                }
            }
        }

        Sleep(10);
    }
}