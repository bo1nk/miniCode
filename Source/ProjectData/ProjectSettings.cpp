
#include "ProjectSettings.h"
#include "../PreferencesView/GlobalPreferences.h"

ProjectSettings::ProjectSettings()
{
	sdk = GlobalPreferences_getDefaultSDK();
	assemblerFlags = ArrayList<String>();
	compilerFlags = ArrayList<String>();
	disabledWarnings = ArrayList<String>();
}

ProjectSettings::ProjectSettings(const ProjectSettings&projSettings)
{
	sdk = projSettings.sdk;
	assemblerFlags = projSettings.assemblerFlags;
	compilerFlags = projSettings.compilerFlags;
	disabledWarnings = projSettings.disabledWarnings;
}

ProjectSettings::~ProjectSettings()
{
	//
}

ProjectSettings& ProjectSettings::operator=(const ProjectSettings&projSettings)
{
	sdk = projSettings.sdk;
	assemblerFlags = projSettings.assemblerFlags;
	compilerFlags = projSettings.compilerFlags;
	disabledWarnings = projSettings.disabledWarnings;
	return *this;
}

void ProjectSettings::setSDK(const String&folder)
{
	sdk = folder;
}

void ProjectSettings::addAssemblerFlag(const String&flag)
{
	assemblerFlags.add(flag.trim());
}

void ProjectSettings::addCompilerFlag(const String&flag)
{
	compilerFlags.add(flag.trim());
}

void ProjectSettings::addDisabledWarning(const String&warning)
{
	String fixedWarning = warning.trim();
	for(int i=0; i<disabledWarnings.size(); i++)
	{
		if(fixedWarning.equals(disabledWarnings.get(i)))
		{
			return;
		}
	}
	disabledWarnings.add(fixedWarning);
}

const String& ProjectSettings::getSDK() const
{
	return sdk;
}

ArrayList<String>& ProjectSettings::getAssemblerFlags()
{
	return assemblerFlags;
}

const ArrayList<String>& ProjectSettings::getAssemblerFlags() const
{
	return assemblerFlags;
}

ArrayList<String>& ProjectSettings::getCompilerFlags()
{
	return compilerFlags;
}

const ArrayList<String>& ProjectSettings::getCompilerFlags() const
{
	return compilerFlags;
}

ArrayList<String>& ProjectSettings::getDisabledWarnings()
{
	return disabledWarnings;
}

const ArrayList<String>& ProjectSettings::getDisabledWarnings() const
{
	return disabledWarnings;
}


