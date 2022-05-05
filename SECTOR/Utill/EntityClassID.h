#pragma once


class EntityClass
{
	public: int EntityObject = NULL;

	public:
		EntityClass(int EntityAddres)
		{
			EntityObject = EntityAddres;
		}


		int Health()
		{
			return Memory::Read<int>(EntityObject + Offset::m_iHealth);
		}


		int ClassID()
		{
			int EntityClassID = Memory::Read<int>(EntityObject + 0x8);

			int Struct1 = Memory::Read<int>(EntityClassID + 0x8);
			int Struct2 = Memory::Read<int>(Struct1 + 0x1);

			return Memory::Read<int>(Struct2 + 0x14);
		}


		int Distance(Vec3 LocalPlayerPos, Vec3 EntityPos)
		{
			return sqrt(pow(LocalPlayerPos.x - EntityPos.x, 2) + pow(LocalPlayerPos.y - EntityPos.y, 2) + pow(LocalPlayerPos.z - EntityPos.z, 2));
		}


		int ActiveWeapon()
		{
			int ActiveWeapon = Memory::Read<int>(EntityObject + Offset::m_hActiveWeapon) & 0xFFF;
			int ActiveWeaponAddres = Memory::Read<int>(GameAddres::Client + Offset::dwEntityList + (ActiveWeapon - 1) * 0x10);

			return Memory::Read<short>(ActiveWeaponAddres + Offset::m_iItemDefinitionIndex);
		}


		int GlowIndex()
		{
			return Memory::Read<int>(EntityObject + Offset::m_iGlowIndex);
		}


		Vec3 BonePos(int BoneID)
		{
			Vec3 EntityBonePos;

			int EntityBoneMatrix = Memory::Read<int>(EntityObject + Offset::m_dwBoneMatrix);

			EntityBonePos.x = Memory::Read<float>(EntityBoneMatrix + 0x30 * BoneID + 0xC);
			EntityBonePos.y = Memory::Read<float>(EntityBoneMatrix + 0x30 * BoneID + 0x1C);
			EntityBonePos.z = Memory::Read<float>(EntityBoneMatrix + 0x30 * BoneID + 0x2C);

			return EntityBonePos;
		}


		Vec3 OriginPos()
		{
			Vec3 EntityPos;

			EntityPos.x = Memory::Read<float>(EntityObject + Offset::m_vecOrigin);
			EntityPos.y = Memory::Read<float>(EntityObject + Offset::m_vecOrigin + 0x4);
			EntityPos.z = Memory::Read<float>(EntityObject + Offset::m_vecOrigin + 0x8);

			return EntityPos;
		}


		Vec3 OriginPosAIM()
		{
			Vec3 EntityPos;

			EntityPos.x = Memory::Read<float>(EntityObject + Offset::m_vecOrigin);
			EntityPos.y = Memory::Read<float>(EntityObject + Offset::m_vecOrigin + 0x4);
			EntityPos.z = Memory::Read<float>(EntityObject + Offset::m_vecOrigin + 0x8);

			EntityPos.z += Memory::Read<float>(EntityObject + Offset::m_vecViewOffset + 0x8);

			return EntityPos;
		}


		bool Teammate()
		{
			int EntityTeamList = Memory::Read<int>(EntityObject + Offset::m_iTeamNum);

			return Addres::MyTeamList == EntityTeamList;
		}


		bool Visible()
		{
			return !Memory::Read<bool>(EntityObject + Offset::m_bSpotted);
		}


		bool LocalPlayer()
		{
			return Addres::LocalPlayer == EntityObject;
		}


		bool Scoped()
		{
			return Memory::Read<bool>(EntityObject + Offset::m_bIsScoped);
		}


		bool Dormant()
		{
			return Memory::Read<bool>(EntityObject + Offset::m_bDormant);
		}


		bool Valid()
		{
			return EntityObject && !LocalPlayer() && Health() > 0 && !Dormant();
		}
};