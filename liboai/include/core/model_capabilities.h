#pragma once

/*
	model_capabilities.h : Model capability detection for OpenAI API parameter handling.
		This header provides utilities for detecting model capabilities and
		determining which API parameters are supported by different model generations.

		Reasoning models (o1, o3, o4-mini, gpt-5*) have different parameter
		requirements than traditional chat models (gpt-3.5, gpt-4, gpt-4o, gpt-4.1).
*/

#include <string>

namespace liboai {

	/*
		@brief Model capability flags for handling API parameter differences
		       across model generations.
	*/
	struct ModelCapabilities {
		// Whether the model supports the temperature parameter
		bool supports_temperature = true;

		// Whether the model supports sampling params: top_p, n, presence_penalty,
		// frequency_penalty, logit_bias, logprobs
		bool supports_sampling_params = true;

		// Whether the model requires max_completion_tokens instead of max_tokens
		bool uses_max_completion_tokens = false;

		// Whether this is a reasoning model (o1, o3, gpt-5*)
		bool is_reasoning_model = false;

		// The preferred system message role ("system" or "developer")
		std::string default_system_role = "system";
	};

	/*
		@brief Returns capability flags for a given model ID.

		Reasoning models have the following restrictions:
		- No temperature, top_p, n, presence_penalty, frequency_penalty, logit_bias
		- Use max_completion_tokens instead of max_tokens
		- Support reasoning_effort parameter

		Model families:
		- GPT-3.5, GPT-4, GPT-4o, GPT-4.1: Traditional chat models, full param support
		- o1, o3, o4-mini: Reasoning models, restricted params
		- GPT-5, GPT-5.1, GPT-5.2: Reasoning models, restricted params

		@param model The model ID string (e.g., "gpt-4", "gpt-5.2", "o3-mini")
		@return ModelCapabilities struct with appropriate flags set
	*/
	inline ModelCapabilities GetModelCapabilities(const std::string& model) {
		ModelCapabilities caps;

		// Check for reasoning model patterns
		// o1, o1-mini, o1-preview
		// o3, o3-mini, o3-pro
		// o4-mini
		// gpt-5, gpt-5-mini, gpt-5.1, gpt-5.2, gpt-5.2-pro, etc.
		bool is_reasoning =
			model.find("o1") != std::string::npos ||
			model.find("o3") != std::string::npos ||
			model.find("o4-mini") != std::string::npos ||
			model.find("gpt-5") != std::string::npos;

		if (is_reasoning) {
			caps.is_reasoning_model = true;
			caps.supports_temperature = false;
			caps.supports_sampling_params = false;
			caps.uses_max_completion_tokens = true;
		}

		// Newer models prefer "developer" role for system messages
		// (though "system" still works for backwards compatibility)
		if (model.find("gpt-4.1") != std::string::npos ||
		    model.find("gpt-5") != std::string::npos) {
			caps.default_system_role = "developer";
		}

		return caps;
	}

	/*
		@brief Checks if a model is a reasoning model.
		@param model The model ID string
		@return true if the model is a reasoning model (o1, o3, gpt-5*)
	*/
	inline bool IsReasoningModel(const std::string& model) {
		return GetModelCapabilities(model).is_reasoning_model;
	}

} // namespace liboai
