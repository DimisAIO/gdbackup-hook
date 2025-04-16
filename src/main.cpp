#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJAccountManager.hpp>
class $modify(GJAccountManager) {
	$override
	void handleIt(bool _requestSentSuccessfully, gd::string _response, gd::string _tag, GJHttpType _httpType) {
		switch(_httpType) {
			case GJHttpType::GetAccountBackupURL:
			case GJHttpType::GetAccountSyncURL:
				_response = "https://gdbackup.141412.xyz";
				break;
			default:
				break;
		}
		GJAccountManager::handleIt(_requestSentSuccessfully,  _response, _tag, _httpType);
	}
};
