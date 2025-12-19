#pragma once

/*
	responses.h : Responses component class for OpenAI.
		This class provides access to the Responses API endpoints.
		It is available via liboai.h through an instantiated liboai::OpenAI
		object after setting necessary authentication information.
*/

#include "../core/authorization.h"
#include "../core/response.h"

namespace liboai {
	class Responses final : private Network {
		public:
			using StreamCallback = std::function<bool(std::string, intptr_t)>;

			Responses(const std::string &root): Network(root) {}
			NON_COPYABLE(Responses)
			NON_MOVABLE(Responses)
			~Responses() = default;

			/*
				@brief Creates a response using the Responses API.

				@param *request  The raw JSON payload for the request.
				@param stream    Optional stream callback for SSE responses.

				@return A liboai::Response object containing response data.
			*/
			LIBOAI_EXPORT liboai::Response create(
				const nlohmann::json& request,
				std::optional<StreamCallback> stream = std::nullopt
			) const & noexcept(false);

			/*
				@brief Asynchronously creates a response using the Responses API.

				@param *request  The raw JSON payload for the request.
				@param stream    Optional stream callback for SSE responses.

				@return A liboai::FutureResponse containing future response data.
			*/
			LIBOAI_EXPORT liboai::FutureResponse create_async(
				const nlohmann::json& request,
				std::optional<StreamCallback> stream = std::nullopt
			) const & noexcept(false);

		private:
			Authorization& auth_ = Authorization::Authorizer();
	};
}
