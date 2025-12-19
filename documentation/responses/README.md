<h1>Responses</h1>
<p>The <code>Responses</code> class is defined in <code>responses.h</code> at <code>liboai::Responses</code>, and its interface can be accessed through a <code>liboai::OpenAI</code> object.</p>

<p>This class provides access to the <a href="https://platform.openai.com/docs/api-reference/responses/create">Responses API</a>. It accepts a raw JSON payload so you can use all current and future fields supported by the API.</p>

<h2>Methods</h2>
<p>This document covers the method(s) located in <code>responses.h</code>. You can find their function signature(s) below.</p>

<h3>Create a Response</h3>
<p>Creates a response from a raw JSON payload. Returns a <code>liboai::Response</code> containing response data.</p>

```cpp
liboai::Response create(
  const nlohmann::json& request,
  std::optional<std::function<bool(std::string, intptr_t)>> stream = std::nullopt
) const & noexcept(false);
```

<h3>Create a Response (async)</h3>
<p>Asynchronously creates a response from a raw JSON payload. Returns a <code>liboai::FutureResponse</code> containing future response data.</p>

```cpp
liboai::FutureResponse create_async(
  const nlohmann::json& request,
  std::optional<std::function<bool(std::string, intptr_t)>> stream = std::nullopt
) const & noexcept(false);
```

<p>When using streaming, include <code>"stream": true</code> in the request and provide a stream callback to receive SSE data.</p>

<h2>Example Usage</h2>
<p>For example usage of the above function(s), please refer to the <a href="./examples">examples</a> folder.</p>
