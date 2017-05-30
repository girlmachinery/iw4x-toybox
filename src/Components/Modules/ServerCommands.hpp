#pragma once

namespace Components
{
	class ServerCommands : public Component
	{
	public:
		ServerCommands();
		~ServerCommands();

		static void OnCommand(std::int32_t cmd, std::function<bool(Command::Params*)> cb);

	private:
		static std::unordered_map < std::int32_t, std::function < bool(Command::Params*) > > Commands;
		static bool OnServerCommand();
		static void OnServerCommandStub();
		static void OnServerCommandPreFailStub();
		static void OnServerCommandFailPrint(int type, const char * trash, ...);
		static void OnServerCommandFailPrintStub();
		static std::uint32_t lastServerCommand;
	};
}
