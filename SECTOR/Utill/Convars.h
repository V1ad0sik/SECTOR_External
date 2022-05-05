#pragma once

namespace ConvarsSetting
{
	bool BostFPS = false;
	bool SvCheats = false;

	bool AspectRatio = false;
	float AspectRatioValue = 2;

	bool GrenadePreview = false;
	bool FullBright = false;
	bool DrawParticles = false;
	bool ForceCrosshair = false;
}


namespace Convars
{
	void SvCheats(int value = 0)
	{
		SetValueINT("sv_cheats", value);
	}


	void BostFPS()
	{
		SetValueINT("r_3dsky", 0);
		SetValueINT("r_shadows", 0);
		SetValueINT("cl_csm_static_prop_shadows", 0);
		SetValueINT("cl_csm_shadows", 0);
		SetValueINT("cl_csm_world_shadows", 0);
		SetValueINT("cl_csm_viewmodel_shadows", 0);
		SetValueINT("cl_csm_rope_shadows", 0);
		SetValueINT("cl_csm_sprite_shadows", 0);
		SetValueINT("cl_disablefreezecam", 0);
		SetValueINT("cl_freezecampanel_position_dynamic", 0);
		SetValueINT("cl_freezecameffects_showholiday", 0);
		SetValueINT("cl_showhelp", 0);
		SetValueINT("cl_autohelp", 0);
		SetValueINT("cl_disablehtmlmotd", 0);
		SetValueINT("mat_postprocess_enable", 0);
		SetValueINT("fog_enable_water_fog", 0);
		SetValueINT("gameinstructor_enable", 0);
		SetValueINT("cl_csm_world_shadows_in_viewmodelcascade", 0);
		SetValueINT("cl_disable_ragdolls", 0);
	}


	void Aspectratio()
	{
		if (ConvarsSetting::AspectRatio)
			SetValueFLOAT("r_aspectratio", ConvarsSetting::AspectRatioValue);

		else
			SetValueFLOAT("r_aspectratio", 1.9);
	}


	void GrenadePreview(int Value)
	{
		SetValueINT("cl_grenadepreview", Value);
	}


	void FullBright(int Value)
	{
		SetValueINT("mat_fullbright", Value);
	}


	void DrawParticles(int Value)
	{
		SetValueINT("r_drawparticles", Value);
	}


	void ForceCrosshair(int Value)
	{
		SetValueINT("weapon_debug_spread_show", Value);
	}
}