#pragma once

namespace Menu
{
	namespace Var
	{
		bool WinState = true;
		bool RenderStarted = false;

		int TabID = 4;
		int BoneID = 0;

		static const char* MouseList[] = { "None", "M1", "M2", "M3", "M4", "M5", "M6" };
		static const char* BoneList[] = { "Head", "Neck", "Chest", "Stomach", "Neares"};
	}


	void SetDescription(const char* Message)
	{
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip(Message);
	}


	namespace ButtonStyle
	{
		void SetBlueStyle()
		{
			ImGuiStyle& Style = ImGui::GetStyle();

			Style.Colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
			Style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			Style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
		}


		void SetBlackStyle()
		{
			ImGuiStyle& Style = ImGui::GetStyle();

			Style.Colors[ImGuiCol_Button] = ImVec4(0.117f, 0.117f, 0.117f, 0.9f);
			Style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.130f, 0.130f, 0.130f, 0.9f);
			Style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.135f, 0.135f, 0.135f, 0.9f);
		}
	}


	void ShowGunList()
	{
		switch (SkinChangerSDK::GunList::ActiveItem)
		{
		case 0: ImGui::Combo("  ", &SkinChangerSDK::GunList::P2000::SkinID, SkinChangerSDK::GunList::P2000::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::P2000::SkinList)); break;
		case 1: ImGui::Combo("  ", &SkinChangerSDK::GunList::USP_S::SkinID, SkinChangerSDK::GunList::USP_S::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::USP_S::SkinList)); break;
		case 2: ImGui::Combo("  ", &SkinChangerSDK::GunList::Glock::SkinID, SkinChangerSDK::GunList::Glock::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Glock::SkinList)); break;
		case 3: ImGui::Combo("  ", &SkinChangerSDK::GunList::Dual_Berettas::SkinID, SkinChangerSDK::GunList::Dual_Berettas::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Dual_Berettas::SkinList)); break;
		case 4: ImGui::Combo("  ", &SkinChangerSDK::GunList::P250::SkinID, SkinChangerSDK::GunList::P250::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::P250::SkinList)); break;
		case 5: ImGui::Combo("  ", &SkinChangerSDK::GunList::Tec_9::SkinID, SkinChangerSDK::GunList::Tec_9::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Tec_9::SkinList)); break;
		case 6: ImGui::Combo("  ", &SkinChangerSDK::GunList::CZ75_Auto::SkinID, SkinChangerSDK::GunList::CZ75_Auto::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::CZ75_Auto::SkinList)); break;
		case 7: ImGui::Combo("  ", &SkinChangerSDK::GunList::Desert_Eagle::SkinID, SkinChangerSDK::GunList::Desert_Eagle::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Desert_Eagle::SkinList)); break;
		case 8: ImGui::Combo("  ", &SkinChangerSDK::GunList::Five_SeveN::SkinID, SkinChangerSDK::GunList::Five_SeveN::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Five_SeveN::SkinList)); break;
		case 9: ImGui::Combo("  ", &SkinChangerSDK::GunList::R8::SkinID, SkinChangerSDK::GunList::R8::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::R8::SkinList)); break;
		case 10: ImGui::Combo("  ", &SkinChangerSDK::GunList::Nova::SkinID, SkinChangerSDK::GunList::Nova::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Nova::SkinList)); break;
		case 11: ImGui::Combo("  ", &SkinChangerSDK::GunList::XM1014::SkinID, SkinChangerSDK::GunList::XM1014::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::XM1014::SkinList)); break;
		case 12: ImGui::Combo("  ", &SkinChangerSDK::GunList::MAG_7::SkinID, SkinChangerSDK::GunList::MAG_7::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::MAG_7::SkinList)); break;
		case 13: ImGui::Combo("  ", &SkinChangerSDK::GunList::M249::SkinID, SkinChangerSDK::GunList::M249::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::M249::SkinList)); break;
		case 14: ImGui::Combo("  ", &SkinChangerSDK::GunList::Negev::SkinID, SkinChangerSDK::GunList::Negev::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Negev::SkinList)); break;
		case 15: ImGui::Combo("  ", &SkinChangerSDK::GunList::Sawed_Off::SkinID, SkinChangerSDK::GunList::Sawed_Off::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Sawed_Off::SkinList)); break;
		case 16: ImGui::Combo("  ", &SkinChangerSDK::GunList::MAC_10::SkinID, SkinChangerSDK::GunList::MAC_10::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::MAC_10::SkinList)); break;
		case 17: ImGui::Combo("  ", &SkinChangerSDK::GunList::MP5_SD::SkinID, SkinChangerSDK::GunList::MP5_SD::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::MP5_SD::SkinList)); break;
		case 18: ImGui::Combo("  ", &SkinChangerSDK::GunList::UMP_45::SkinID, SkinChangerSDK::GunList::UMP_45::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::UMP_45::SkinList)); break;
		case 19: ImGui::Combo("  ", &SkinChangerSDK::GunList::P90::SkinID, SkinChangerSDK::GunList::P90::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::P90::SkinList)); break;
		case 20: ImGui::Combo("  ", &SkinChangerSDK::GunList::PP_19::SkinID, SkinChangerSDK::GunList::PP_19::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::PP_19::SkinList)); break;
		case 21: ImGui::Combo("  ", &SkinChangerSDK::GunList::MP9::SkinID, SkinChangerSDK::GunList::MP9::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::MP9::SkinList)); break;
		case 22: ImGui::Combo("  ", &SkinChangerSDK::GunList::MP7::SkinID, SkinChangerSDK::GunList::MP7::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::MP7::SkinList)); break;
		case 23: ImGui::Combo("  ", &SkinChangerSDK::GunList::FAMAS::SkinID, SkinChangerSDK::GunList::FAMAS::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::FAMAS::SkinList)); break;
		case 24: ImGui::Combo("  ", &SkinChangerSDK::GunList::M4A4::SkinID, SkinChangerSDK::GunList::M4A4::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::M4A4::SkinList)); break;
		case 25: ImGui::Combo("  ", &SkinChangerSDK::GunList::M4A1_S::SkinID, SkinChangerSDK::GunList::M4A1_S::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::M4A1_S::SkinList)); break;
		case 26: ImGui::Combo("  ", &SkinChangerSDK::GunList::SSG_08::SkinID, SkinChangerSDK::GunList::SSG_08::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::SSG_08::SkinList)); break;
		case 27: ImGui::Combo("  ", &SkinChangerSDK::GunList::AUG::SkinID, SkinChangerSDK::GunList::AUG::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::AUG::SkinList)); break;
		case 28: ImGui::Combo("  ", &SkinChangerSDK::GunList::AWP::SkinID, SkinChangerSDK::GunList::AWP::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::AWP::SkinList)); break;
		case 29: ImGui::Combo("  ", &SkinChangerSDK::GunList::SCAR_20::SkinID, SkinChangerSDK::GunList::SCAR_20::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::SCAR_20::SkinList)); break;
		case 30: ImGui::Combo("  ", &SkinChangerSDK::GunList::Galil::SkinID, SkinChangerSDK::GunList::Galil::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::Galil::SkinList)); break;
		case 31: ImGui::Combo("  ", &SkinChangerSDK::GunList::AK_47::SkinID, SkinChangerSDK::GunList::AK_47::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::AK_47::SkinList)); break;
		case 32: ImGui::Combo("  ", &SkinChangerSDK::GunList::SG_553::SkinID, SkinChangerSDK::GunList::SG_553::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::SG_553::SkinList)); break;
		case 33: ImGui::Combo("  ", &SkinChangerSDK::GunList::C3SG1::SkinID, SkinChangerSDK::GunList::C3SG1::SkinList, ToolSDK::GetArraySize(SkinChangerSDK::GunList::C3SG1::SkinList)); break;
		}
	}
}