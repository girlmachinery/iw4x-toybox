#pragma once

namespace Components
{
	struct tablelookuprequest_s
	{
		std::uint8_t padding[4];
		char* tablename;
		std::uint8_t padding2[4];
		std::int32_t tableRow;
		std::uint8_t padding3[4];
		std::int32_t tableColumn;
	};
	struct tablelookupresult_s
	{
		std::uint32_t dunno;
		const char* result;
	};
	struct playercarddata_s
	{
		std::uint32_t padding;
		std::uint32_t playercardNumber;
		std::uint32_t unknown;
		std::uint32_t unknown2;
		std::uint32_t level; //Level is counted from 0 -> Value 69 is Level 70
		std::uint32_t prestige;
		std::uint32_t padding2;
		char name[40];
	};

	struct CClient
	{
		std::uint32_t IsValid; 				// 0x0000 
		std::uint32_t IsValid2; 			// 0x0004 
		std::uint32_t ClientNumber; 		// 0x0008 
		char Name[16]; 						// 0x000C 
		std::uint32_t Team; 				// 0x001C 
		std::uint32_t Team2; 				// 0x0020 
		std::uint32_t Rank; 				// 0x0024 (rank - 1)
		std::uint32_t Prestige; 			// 0x0028
		std::uint32_t Perks; 				// 0x002C 
		std::uint32_t Kills; 				// 0x0030
		std::uint32_t Score; 				// 0x0034 
		std::uint8_t _0x0038[968];
		std::uint32_t ViewAngles; 			// 0x0400 
		std::uint8_t _0x040C[136];
		std::uint32_t IsShooting; 			// 0x0494 
		std::uint8_t _0x0498[4];
		std::uint32_t IsZoomed; 			// 0x049C 
		std::uint8_t _0x04A0[68];
		std::uint32_t weaponID; 			// 0x04E4 
		std::uint8_t _0x04E8[24];
		std::uint32_t weaponID2; 			// 0x0500 
		std::uint8_t _0x0504[40];
		std::uint8_t _padding[8];
	};

	class CardTitles : public Component
	{
	public:
		static Game::dvar_t* CustomTitleDvar;

		static void ParseCustomTitles(const char * msg);

		CardTitles();
		~CardTitles();

	private:
		static std::vector < std::string > CustomTitles;

		static CClient * GetClientByIndex(std::uint32_t index);
		static std::int32_t GetPlayerCardClientInfo(std::int32_t lookupResult, playercarddata_s * data);
		static void GetPlayerCardClientInfoStub();
		static void LocalizationSkipHookStub();
		static void TableLookupByRowHookStub();

	};
}
