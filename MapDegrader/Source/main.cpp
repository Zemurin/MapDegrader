#include "Log.h"
#include "MapDegrader.h"
#include "OSCompatibilityLayer.h"

int main(const int argc, const char* argv[])
{
	try
	{
		std::string gamePath;
		auto wGamePath = commonItems::getSteamInstallPath("1158310");
		if (!wGamePath)
		{
			Log(LogLevel::Info) << "CK3 not found, paths default to local directory.";
		}
		else
		{
			// We're degrading to UTF8 as I don't intend to support non-standard locations.
			gamePath = commonItems::UTF16ToUTF8(*wGamePath) + "/game/";
			Log(LogLevel::Info) << "CK3 installation found at: " << gamePath;
		}
		MapDegrader mapDegrader;
		mapDegrader.degradeMap(gamePath);
		Log(LogLevel::Info) << "Done.";

		return 0;
	}

	catch (const std::exception& e)
	{
		Log(LogLevel::Error) << e.what();
		return -1;
	}
}