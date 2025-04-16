#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/binding/GJHttpResult.hpp>
#include <Geode/modify/GJAccountManager.hpp>
class $modify(GJAccountManager) {
	void handleIt(bool _requestSentSuccessfully, std::string _response, std::string _tag, GJHttpType _httpType) {
		switch(_httpType) {
			case GJHttpType::kGJHttpTypeGetAccountBackupURL:
			case GJHttpType::kGJHttpTypeGetAccountSyncURL:
				_response = "https://gdbackup.141412.xyz";
				break;
			default:
				return;
		}
		GJAccountManager::handleIt(_requestSentSuccessfully,  _response, _tag, _httpType);
	}
};