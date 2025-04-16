#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJAccountManager.hpp>
class $modify(GJAccountManager) {
	void handleIt(bool _requestSentSuccessfully, std::string _response, std::string _tag, GJHttpType _httpType) {
		switch(_httpType) {
			case 0x36:
			case 0x37:
				_response = "https://gdbackup.141412.xyz";
				break;
			default:
				return;
		}
		GJAccountManager::handleIt(_requestSentSuccessfully,  _response, _tag, _httpType);
	}
};