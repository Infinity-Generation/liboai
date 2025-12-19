#include "../include/components/responses.h"

liboai::Response liboai::Responses::create(const nlohmann::json& request, std::optional<StreamCallback> stream) const & noexcept(false) {
	Response res;
	res = this->Request(
		Method::HTTP_POST, this->openai_root_, "/responses", "application/json",
		this->auth_.GetAuthorizationHeaders(),
		netimpl::components::Body {
			request.dump(4)
		},
		stream ? netimpl::components::WriteCallback{std::move(stream.value())} : netimpl::components::WriteCallback{},
		this->auth_.GetProxies(),
		this->auth_.GetProxyAuth(),
		this->auth_.GetMaxTimeout()
	);

	return res;
}

liboai::FutureResponse liboai::Responses::create_async(const nlohmann::json& request, std::optional<StreamCallback> stream) const & noexcept(false) {
	return std::async(std::launch::async, &liboai::Responses::create, this, std::cref(request), stream);
}
