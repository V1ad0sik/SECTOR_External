#pragma once


namespace Config
{
	namespace Skinchanger
	{
		void Load()
		{
			ifstream Config(GetSectorPath::SkinConfig());

			if (Config.is_open())
			{
				json SkinList;

				try
				{
					SkinList = json::parse(Config);
				}

				catch (exception)
				{
					MessageBox(0, "Structure reading error.", GetSectorPath::SkinConfig().c_str(), 0);
					return;
				}

				SkinChangerSDK::GunList::P2000::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::P2000::SkinIndex, SkinList["P2000"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::P2000::SkinIndex));
				SkinChangerSDK::GunList::USP_S::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::USP_S::SkinIndex, SkinList["USP-S"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::USP_S::SkinIndex));
				SkinChangerSDK::GunList::Glock::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Glock::SkinIndex, SkinList["Glock"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Glock::SkinIndex));
				SkinChangerSDK::GunList::Dual_Berettas::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Dual_Berettas::SkinIndex, SkinList["Dual Berettas"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Dual_Berettas::SkinIndex));
				SkinChangerSDK::GunList::P250::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::P250::SkinIndex, SkinList["P250"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::P250::SkinIndex));
				SkinChangerSDK::GunList::Tec_9::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Tec_9::SkinIndex, SkinList["Tec-9"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Tec_9::SkinIndex));
				SkinChangerSDK::GunList::CZ75_Auto::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::CZ75_Auto::SkinIndex, SkinList["CZ75-Auto"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::CZ75_Auto::SkinIndex));
				SkinChangerSDK::GunList::Desert_Eagle::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Desert_Eagle::SkinIndex, SkinList["Desert Eagle"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Desert_Eagle::SkinIndex));
				SkinChangerSDK::GunList::Five_SeveN::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Five_SeveN::SkinIndex, SkinList["Five-SeveN"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Five_SeveN::SkinIndex));
				SkinChangerSDK::GunList::R8::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::R8::SkinIndex, SkinList["R8"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::R8::SkinIndex));
				SkinChangerSDK::GunList::Nova::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Nova::SkinIndex, SkinList["Nova"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Nova::SkinIndex));
				SkinChangerSDK::GunList::XM1014::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::XM1014::SkinIndex, SkinList["XM1014"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::XM1014::SkinIndex));
				SkinChangerSDK::GunList::MAG_7::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::MAG_7::SkinIndex, SkinList["MAG-7"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::MAG_7::SkinIndex));
				SkinChangerSDK::GunList::M249::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::M249::SkinIndex, SkinList["M249"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::M249::SkinIndex));
				SkinChangerSDK::GunList::Negev::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Negev::SkinIndex, SkinList["Negev"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Negev::SkinIndex));
				SkinChangerSDK::GunList::Sawed_Off::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Sawed_Off::SkinIndex, SkinList["Sawed-Off"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Sawed_Off::SkinIndex));
				SkinChangerSDK::GunList::MAC_10::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::MAC_10::SkinIndex, SkinList["MAC-10"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::MAC_10::SkinIndex));
				SkinChangerSDK::GunList::MP5_SD::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::MP5_SD::SkinIndex, SkinList["MP5-SD"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::MP5_SD::SkinIndex));
				SkinChangerSDK::GunList::UMP_45::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::UMP_45::SkinIndex, SkinList["UMP-45"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::UMP_45::SkinIndex));
				SkinChangerSDK::GunList::P90::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::P90::SkinIndex, SkinList["P90"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::P90::SkinIndex));
				SkinChangerSDK::GunList::PP_19::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::PP_19::SkinIndex, SkinList["PP-19"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::PP_19::SkinIndex));
				SkinChangerSDK::GunList::MP9::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::MP9::SkinIndex, SkinList["MP9"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::MP9::SkinIndex));
				SkinChangerSDK::GunList::MP7::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::MP7::SkinIndex, SkinList["MP7"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::MP7::SkinIndex));
				SkinChangerSDK::GunList::FAMAS::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::FAMAS::SkinIndex, SkinList["FAMAS"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::FAMAS::SkinIndex));
				SkinChangerSDK::GunList::M4A4::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::M4A4::SkinIndex, SkinList["M4A4"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::M4A4::SkinIndex));
				SkinChangerSDK::GunList::M4A1_S::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::M4A1_S::SkinIndex, SkinList["M4A1-S"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::M4A1_S::SkinIndex));
				SkinChangerSDK::GunList::SSG_08::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::SSG_08::SkinIndex, SkinList["SSG 08"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::SSG_08::SkinIndex));
				SkinChangerSDK::GunList::AUG::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::AUG::SkinIndex, SkinList["AUG"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::AUG::SkinIndex));
				SkinChangerSDK::GunList::AWP::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::AWP::SkinIndex, SkinList["AWP"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::AWP::SkinIndex));
				SkinChangerSDK::GunList::SCAR_20::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::SCAR_20::SkinIndex, SkinList["SCAR-20"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::SCAR_20::SkinIndex));
				SkinChangerSDK::GunList::Galil::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::Galil::SkinIndex, SkinList["Galil"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::Galil::SkinIndex));
				SkinChangerSDK::GunList::AK_47::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::AK_47::SkinIndex, SkinList["AK-47"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::AK_47::SkinIndex));
				SkinChangerSDK::GunList::SG_553::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::SG_553::SkinIndex, SkinList["SG 553"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::SG_553::SkinIndex));
				SkinChangerSDK::GunList::C3SG1::SkinID = ToolSDK::FindIndex(SkinChangerSDK::GunList::C3SG1::SkinIndex, SkinList["C3SG1"].get<int>(), ToolSDK::GetArraySize(SkinChangerSDK::GunList::C3SG1::SkinIndex));

				SkinChangerSDK::ApplyGunIndex();
			}
		}


		void Save()
		{
			CreateDirectory(GetSectorPath::Config().c_str(), NULL);

			json ConfigList;

			ConfigList["P2000"] = SkinChangerSDK::Gun::P2000;
			ConfigList["USP-S"] = SkinChangerSDK::Gun::USP_S;
			ConfigList["Glock"] = SkinChangerSDK::Gun::Glock;
			ConfigList["Dual Berettas"] = SkinChangerSDK::Gun::Dual_Berettas;
			ConfigList["Tec-9"] = SkinChangerSDK::Gun::Tec_9;
			ConfigList["P250"] = SkinChangerSDK::Gun::P250;
			ConfigList["CZ75-Auto"] = SkinChangerSDK::Gun::CZ75_Auto;
			ConfigList["Desert Eagle"] = SkinChangerSDK::Gun::Desert_Eagle;
			ConfigList["Five-SeveN"] = SkinChangerSDK::Gun::Five_SeveN;
			ConfigList["R8"] = SkinChangerSDK::Gun::R8;
			ConfigList["Nova"] = SkinChangerSDK::Gun::Nova;
			ConfigList["XM1014"] = SkinChangerSDK::Gun::XM1014;
			ConfigList["MAG-7"] = SkinChangerSDK::Gun::MAG_7;
			ConfigList["M249"] = SkinChangerSDK::Gun::M249;
			ConfigList["Negev"] = SkinChangerSDK::Gun::Negev;
			ConfigList["Sawed-Off"] = SkinChangerSDK::Gun::Sawed_Off;
			ConfigList["MAC-10"] = SkinChangerSDK::Gun::MAC_10;
			ConfigList["MP5-SD"] = SkinChangerSDK::Gun::MP5_SD;
			ConfigList["UMP-45"] = SkinChangerSDK::Gun::UMP_45;
			ConfigList["P90"] = SkinChangerSDK::Gun::P90;
			ConfigList["PP-19"] = SkinChangerSDK::Gun::PP_19;
			ConfigList["MP9"] = SkinChangerSDK::Gun::MP9;
			ConfigList["MP7"] = SkinChangerSDK::Gun::MP7;
			ConfigList["FAMAS"] = SkinChangerSDK::Gun::FAMAS;
			ConfigList["M4A4"] = SkinChangerSDK::Gun::M4A4;
			ConfigList["M4A1-S"] = SkinChangerSDK::Gun::M4A1_S;
			ConfigList["SSG 08"] = SkinChangerSDK::Gun::SSG_08;
			ConfigList["AUG"] = SkinChangerSDK::Gun::AUG;
			ConfigList["AWP"] = SkinChangerSDK::Gun::AWP;
			ConfigList["SCAR-20"] = SkinChangerSDK::Gun::SCAR_20;
			ConfigList["Galil"] = SkinChangerSDK::Gun::Galil;
			ConfigList["AK-47"] = SkinChangerSDK::Gun::AK_47;
			ConfigList["SG 553"] = SkinChangerSDK::Gun::SG_553;
			ConfigList["C3SG1"] = SkinChangerSDK::Gun::C3SG1;


			try
			{
				ofstream Config;

				Config.open(GetSectorPath::SkinConfig().c_str());
				Config << ConfigList.dump();
				Config.close();
			}

			catch (exception)
			{
				MessageBox(0, "Erorr save skin to json.", "Save", 0);
			}
		}


		void SetToDefault()
		{
			CreateDirectory(GetSectorPath::Config().c_str(), NULL);

			json ConfigList;

			ConfigList["P2000"] = 894;
			ConfigList["USP-S"] = 504;
			ConfigList["Glock"] = 437;
			ConfigList["Dual Berettas"] = 447;
			ConfigList["P250"] = 551;
			ConfigList["Tec-9"] = 684;
			ConfigList["CZ75-Auto"] = 297;
			ConfigList["Desert Eagle"] = 37;
			ConfigList["Five-SeveN"] = 906;
			ConfigList["R8"] = 12;
			ConfigList["Nova"] = 62;
			ConfigList["XM1014"] = 850;
			ConfigList["MAG-7"] = 198;
			ConfigList["M249"] = 401;
			ConfigList["Negev"] = 317;
			ConfigList["Sawed-Off"] = 953;
			ConfigList["MAC-10"] = 812;
			ConfigList["MP5-SD"] = 812;
			ConfigList["UMP-45"] = 851;
			ConfigList["P90"] = 977;
			ConfigList["PP-19"] = 973;
			ConfigList["MP9"] = 697;
			ConfigList["MP7"] = 847;
			ConfigList["FAMAS"] = 723;
			ConfigList["M4A4"] = 844;
			ConfigList["M4A1-S"] = 714;
			ConfigList["SSG 08"] = 899;
			ConfigList["AUG"] = 280;
			ConfigList["AWP"] = 279;
			ConfigList["SCAR-20"] = 954;
			ConfigList["Galil"] = 379;
			ConfigList["AK-47"] = 885;
			ConfigList["SG 553"] = 897;
			ConfigList["C3SG1"] = 74;


			try
			{
				ofstream Config;

				Config.open(GetSectorPath::SkinConfig().c_str());
				Config << ConfigList.dump();
				Config.close();
			}

			catch (exception)
			{
				MessageBox(0, "Erorr save skin to json.", "SetToDefault", 0);
			}
		}
	}

	namespace Cheat
	{
		void Load()
		{
			ifstream File(GetSectorPath::CheatConfig().c_str());

			if (File.is_open())
			{
				json Setting = json::parse(File);

				try
				{
					GlowESPSetting::Status = Setting["GlowESP"]["Status"];
					GlowESPSetting::TeamCheck = Setting["GlowESP"]["TeamCheck"];
					GlowESPSetting::Color[0] = Setting["GlowESP"]["Color"]["R"];
					GlowESPSetting::Color[1] = Setting["GlowESP"]["Color"]["G"];
					GlowESPSetting::Color[2] = Setting["GlowESP"]["Color"]["B"];
					GlowESPSetting::Line = Setting["GlowESP"]["Line"];

					if (GlowESPSetting::Status)
					{
						thread _GlowESP(GlowESP);
						_GlowESP.detach();
					}
				}

				catch (exception) {}

				
				try
				{
					GlowESP_DistanceSetting::Status = Setting["GlowESP_Distance"]["Status"];
					GlowESP_DistanceSetting::TeamCheck = Setting["GlowESP_Distance"]["TeamCheck"];
					GlowESP_DistanceSetting::Distance = Setting["GlowESP_Distance"]["Distance"];
					GlowESP_DistanceSetting::Color[0] = Setting["GlowESP_Distance"]["Color"]["R"];
					GlowESP_DistanceSetting::Color[1] = Setting["GlowESP_Distance"]["Color"]["G"];
					GlowESP_DistanceSetting::Color[2] = Setting["GlowESP_Distance"]["Color"]["B"];
					GlowESP_DistanceSetting::Line = Setting["GlowESP_Distance"]["Line"];

					if (GlowESP_DistanceSetting::Status)
					{
						thread _GlowESP_Distance(GlowESP_Distance);
						_GlowESP_Distance.detach();
					}
				}

				catch (exception) {}


				try
				{
					GlowESP_HPSetting::Status = Setting["GlowESP_HP"]["Status"];
					GlowESP_HPSetting::TeamCheck = Setting["GlowESP_HP"]["TeamCheck"];
					GlowESP_HPSetting::Line = Setting["GlowESP_HP"]["Line"];

					if (GlowESP_HPSetting::Status)
					{
						thread _GlowESP_HP(GlowESP_HP);
						_GlowESP_HP.detach();
					}
				}

				catch (exception) {}


				try
				{
					RenderSetting::RenderIsStarted = Setting["Render"]["Status"];
					RenderSetting::BoxESP = Setting["Render"]["Box_ESP_Status"];
					RenderSetting::TeamCheck = Setting["Render"]["TeamCheck"];
					RenderSetting::HP = Setting["Render"]["HP_Status"];
					RenderSetting::Gun = Setting["Render"]["Gun_Status"];

					if (RenderSetting::RenderIsStarted && !Menu::Var::RenderStarted)
					{
						Menu::Var::RenderStarted = true;

						thread _BoxESP(BoxESP);
						_BoxESP.detach();
					}
				}

				catch (exception) {}


				try
				{
					ChamsSetting::Status = Setting["Chams"]["Status"];
					ChamsSetting::TeamCheck = Setting["Chams"]["TeamCheck"];
					ChamsSetting::Color[0] = Setting["Chams"]["Color"]["R"];
					ChamsSetting::Color[1] = Setting["Chams"]["Color"]["G"];
					ChamsSetting::Color[2] = Setting["Chams"]["Color"]["B"];

					if (ChamsSetting::Status)
					{
						thread _Chams(Chams);
						_Chams.detach();
					}
				}

				catch (exception) {}


				try
				{
					NightModSetting::Status = Setting["NightMod"]["Status"];
					NightModSetting::Value = Setting["NightMod"]["Value"];

					if (NightModSetting::Status)
					{
						thread _NightMod(NightMod);
						_NightMod.detach();
					}
				}

				catch (exception) {}


				try
				{
					BrightnessSetting::Status = Setting["Brightness"]["Status"];
					BrightnessSetting::Value = Setting["Brightness"]["Value"];

					if (BrightnessSetting::Status)
					{
						thread _Brightness(Brightness);
						_Brightness.detach();
					}
				}

				catch (exception) {}


				try
				{
					FovChangerSetting::Status = Setting["FovChanger"]["Status"];
					FovChangerSetting::Fov = Setting["FovChanger"]["Fov"];

					if (FovChangerSetting::Status)
					{
						thread _FovChanger(FovChanger);
						_FovChanger.detach();
					}
				}

				catch (exception) {}


				try
				{
					AimBotSetting::Status = Setting["AimBot"]["Status"];
					AimBotSetting::OnlyVisible = Setting["AimBot"]["OnlyVisible"];
					AimBotSetting::TeamCheck = Setting["AimBot"]["TeamCheck"];
					AimBotSetting::Key = Setting["AimBot"]["Key"];
					AimBotSetting::FOV = Setting["AimBot"]["FOV"];
					AimBotSetting::Smooth = Setting["AimBot"]["Smooth"];
					AimBotSetting::Bone = Setting["AimBot"]["Bone"];

					Menu::Var::BoneID = Setting["MenuData"]["BoneID"];

					if (Menu::Var::BoneID == 4)
						AimBotSetting::Nearest = true;

					if (AimBotSetting::Status)
					{
						thread _AimBot(AimBot);
						_AimBot.detach();
					}
				}

				catch (exception) {}


				try
				{
					TriggerBotSetting::Status = Setting["TriggerBot"]["Status"];
					TriggerBotSetting::TeamCheck = Setting["TriggerBot"]["TeamCheck"];
					TriggerBotSetting::Delay = Setting["TriggerBot"]["Delay"];
					TriggerBotSetting::Key = Setting["TriggerBot"]["Key"];

					if (TriggerBotSetting::Status)
					{
						thread _TriggerBot(TriggerBot);
						_TriggerBot.detach();
					}
				}

				catch (exception) {}


				try
				{
					SkinChangerSetting::Status = Setting["SkinChanger"]["Status"];

					if (SkinChangerSetting::Status)
					{
						thread _SkinChanger(SkinChanger);
						_SkinChanger.detach();
					}


					KnifeChangerSetting::Status = Setting["KnifeChanger"]["Status"];

					if (KnifeChangerSetting::Status)
					{
						thread _KnifeChanger(KnifeChanger);
						_KnifeChanger.detach();
					}

				}

				catch (exception) {}


				try
				{
					AutoPistolSetting::Status = Setting["AutoPistol"]["Status"];
					BunnyHopSetting::Status = Setting["BunnyHop"]["Status"];
					RadarHackSetting::Status = Setting["RadarHack"]["Status"];

					if (AutoPistolSetting::Status)
					{
						thread _AutoPistol(AutoPistol);
						_AutoPistol.detach();
					}

					if (BunnyHopSetting::Status)
					{
						thread _BunnyHop(BunnyHop);
						_BunnyHop.detach();
					}

					if (RadarHackSetting::Status)
					{
						thread _RadarHack(RadarHack);
						_RadarHack.detach();
					}


					NoFlashSetting::Status = Setting["NoFlash"]["Status"];
					NoFlashSetting::Value = Setting["NoFlash"]["Value"];

					if (NoFlashSetting::Status)
					{
						thread _NoFlash(NoFlash);
						_NoFlash.detach();
					}


					/*FakeLagSetting::Status = Setting["FakeLag"]["Statuts"];
					FakeLagSetting::Tick = Setting["FakeLag"]["Tick"];

					if (FakeLagSetting::Status)
					{
						thread _FakeLag(FakeLag);
						_FakeLag.detach();
					}*/
				}

				catch (exception) {}


				try
				{
					ConvarsSetting::BostFPS = Setting[("Convars")][("BostFPS")];
					ConvarsSetting::SvCheats = Setting[("Convars")][("SvCheats")];
					ConvarsSetting::AspectRatio = Setting[("Convars")][("AspectRatio")];
					ConvarsSetting::AspectRatioValue = Setting[("Convars")][("AspectRatioValue")];
					ConvarsSetting::GrenadePreview = Setting[("Convars")][("GrenadePreview")];
					ConvarsSetting::FullBright = Setting[("Convars")][("FullBright")];
					ConvarsSetting::DrawParticles = Setting[("Convars")][("DrawParticles")];
					ConvarsSetting::ForceCrosshair = Setting[("Convars")][("ForceCrosshair")];


					if (ConvarsSetting::BostFPS)
					{
						thread _BostFPS(Convars::BostFPS);
						_BostFPS.detach();
					}

					if (ConvarsSetting::SvCheats)
					{
						thread _SvCheats(Convars::SvCheats, 1);
						_SvCheats.detach();
					}

					if (ConvarsSetting::AspectRatio)
					{
						thread _Aspectratio(Convars::Aspectratio);
						_Aspectratio.detach();
					}

					if (ConvarsSetting::GrenadePreview)
					{
						thread _GrenadePreview(Convars::GrenadePreview, 1);
						_GrenadePreview.detach();
					}

					if (ConvarsSetting::FullBright)
					{
						thread _FullBright(Convars::FullBright, 1);
						_FullBright.detach();
					}

					if (ConvarsSetting::DrawParticles)
					{
						thread _DrawParticles(Convars::DrawParticles, 1);
						_DrawParticles.detach();
					}

					if (ConvarsSetting::ForceCrosshair)
					{
						thread _ForceCrosshair(Convars::ForceCrosshair, 3);
						_ForceCrosshair.detach();
					}
				}

				catch (exception) {}
			}
		}


		void Save()
		{
			CreateDirectory(GetSectorPath::Config().c_str(), NULL);


			json SaveConfig;

			SaveConfig[("GlowESP")][("Status")] = GlowESPSetting::Status;
			SaveConfig[("GlowESP")][("TeamCheck")] = GlowESPSetting::TeamCheck;

			SaveConfig[("GlowESP")][("Color")][("R")] = GlowESPSetting::Color[0];
			SaveConfig[("GlowESP")][("Color")][("G")] = GlowESPSetting::Color[1];
			SaveConfig[("GlowESP")][("Color")][("B")] = GlowESPSetting::Color[2];

			SaveConfig[("GlowESP")][("Line")] = GlowESPSetting::Line;

			SaveConfig[("GlowESP_Distance")][("Status")] = GlowESP_DistanceSetting::Status;
			SaveConfig[("GlowESP_Distance")][("TeamCheck")] = GlowESP_DistanceSetting::TeamCheck;
			SaveConfig[("GlowESP_Distance")][("Distance")] = GlowESP_DistanceSetting::Distance;

			SaveConfig[("GlowESP_Distance")][("Color")][("R")] = GlowESP_DistanceSetting::Color[0];
			SaveConfig[("GlowESP_Distance")][("Color")][("G")] = GlowESP_DistanceSetting::Color[1];
			SaveConfig[("GlowESP_Distance")][("Color")][("B")] = GlowESP_DistanceSetting::Color[2];

			SaveConfig[("GlowESP_Distance")][("Line")] = GlowESP_DistanceSetting::Line;

			SaveConfig[("GlowESP_HP")][("Status")] = GlowESP_HPSetting::Status;
			SaveConfig[("GlowESP_HP")][("TeamCheck")] = GlowESP_HPSetting::TeamCheck;
			SaveConfig[("GlowESP_HP")][("Line")] = GlowESP_HPSetting::Line;

			SaveConfig[("Render")][("Status")] = RenderSetting::RenderIsStarted;
			SaveConfig[("Render")][("Box_ESP_Status")] = RenderSetting::BoxESP;
			SaveConfig[("Render")][("TeamCheck")] = RenderSetting::TeamCheck;
			SaveConfig[("Render")][("HP_Status")] = RenderSetting::HP;
			SaveConfig[("Render")][("Gun_Status")] = RenderSetting::Gun;

			SaveConfig[("Chams")][("Status")] = ChamsSetting::Status;
			SaveConfig[("Chams")][("TeamCheck")] = ChamsSetting::TeamCheck;
			SaveConfig[("Chams")][("Color")][("R")] = ChamsSetting::Color[0];
			SaveConfig[("Chams")][("Color")][("G")] = ChamsSetting::Color[1];
			SaveConfig[("Chams")][("Color")][("B")] = ChamsSetting::Color[2];

			SaveConfig[("NightMod")][("Status")] = NightModSetting::Status;
			SaveConfig[("NightMod")][("Value")] = NightModSetting::Value;

			SaveConfig[("Brightness")][("Status")] = BrightnessSetting::Status;
			SaveConfig[("Brightness")][("Value")] = BrightnessSetting::Value;

			SaveConfig[("FovChanger")][("Status")] = FovChangerSetting::Status;
			SaveConfig[("FovChanger")][("Fov")] = FovChangerSetting::Fov;

			SaveConfig[("AimBot")][("Status")] = AimBotSetting::Status;
			SaveConfig[("AimBot")][("OnlyVisible")] = AimBotSetting::OnlyVisible;
			SaveConfig[("AimBot")][("TeamCheck")] = AimBotSetting::TeamCheck;
			SaveConfig[("AimBot")][("Key")] = AimBotSetting::Key;
			SaveConfig[("AimBot")][("FOV")] = AimBotSetting::FOV;
			SaveConfig[("AimBot")][("Smooth")] = AimBotSetting::Smooth;
			SaveConfig[("AimBot")][("Bone")] = AimBotSetting::Bone;

			SaveConfig[("MenuData")][("BoneID")] = Menu::Var::BoneID;

			SaveConfig[("TriggerBot")][("Status")] = TriggerBotSetting::Status;
			SaveConfig[("TriggerBot")][("TeamCheck")] = TriggerBotSetting::TeamCheck;
			SaveConfig[("TriggerBot")][("Delay")] = TriggerBotSetting::Delay;
			SaveConfig[("TriggerBot")][("Key")] = TriggerBotSetting::Key;

			SaveConfig[("SkinChanger")][("Status")] = SkinChangerSetting::Status;
			SaveConfig[("KnifeChanger")][("Status")] = KnifeChangerSetting::Status;

			SaveConfig[("AutoPistol")][("Status")] = AutoPistolSetting::Status;
			SaveConfig[("BunnyHop")][("Status")] = BunnyHopSetting::Status;
			SaveConfig[("RadarHack")][("Status")] = RadarHackSetting::Status;

			SaveConfig[("NoFlash")][("Status")] = NoFlashSetting::Status;
			SaveConfig[("NoFlash")][("Value")] = NoFlashSetting::Value;

			/*SaveConfig[("FakeLag")][("Statuts")] = FakeLagSetting::Status;
			SaveConfig[("FakeLag")][("Tick")] = FakeLagSetting::Tick;*/

			SaveConfig[("Convars")][("BostFPS")] = ConvarsSetting::BostFPS;
			SaveConfig[("Convars")][("SvCheats")] = ConvarsSetting::SvCheats;
			SaveConfig[("Convars")][("AspectRatio")] = ConvarsSetting::AspectRatio;
			SaveConfig[("Convars")][("AspectRatioValue")] = ConvarsSetting::AspectRatioValue;
			SaveConfig[("Convars")][("GrenadePreview")] = ConvarsSetting::GrenadePreview;
			SaveConfig[("Convars")][("FullBright")] = ConvarsSetting::FullBright;
			SaveConfig[("Convars")][("DrawParticles")] = ConvarsSetting::DrawParticles;
			SaveConfig[("Convars")][("ForceCrosshair")] = ConvarsSetting::ForceCrosshair;


			try
			{
				ofstream File;

				File.open(GetSectorPath::CheatConfig().c_str());
				File << SaveConfig.dump();
				File.close();
			}

			catch (exception)
			{
				MessageBox(0, "Erorr save setting to JSON.", "Save", 0);
			}
		}
	}
}