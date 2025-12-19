# liboai Roadmap

This is a living backlog of improvements and ideas as we deepen our use of the library. It is intentionally lightweight and updated as we discover new needs.

## Now
- Responses API support (GPT-5.2, gpt-5.2-pro)
- Keep all existing APIs stable and intact

## Next
- Responses streaming helpers and SSE parsing
- ResponseInput helper to build Responses `input` items
- `output_text` convenience helper for Responses outputs
- Structured outputs helpers for `text.format`
- Tool definition builders for Responses (`tools`, `tool_choice`)

## Later
- More robust testing coverage (unit + integration samples)
- Improved error messaging with request context (safe, no secrets)
- Expanded docs and cookbook-style examples
- Performance pass on JSON construction and streaming

## Observations
- The Conversation class is useful for Chat Completions; Responses lacks an equivalent.
- The library is stable but needs modernization for new OpenAI primitives.
- Maintaining compatibility is critical for existing users.
