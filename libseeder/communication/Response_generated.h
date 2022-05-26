// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_RESPONSE_SEEDER_H_
#define FLATBUFFERS_GENERATED_RESPONSE_SEEDER_H_

#include "flatbuffers/flatbuffers.h"

namespace Seeder {

struct HelloResponse;
struct HelloResponseBuilder;

struct GetPeersResponse;
struct GetPeersResponseBuilder;

struct Response;
struct ResponseBuilder;

enum HelloRequestResult : int8_t {
  HelloRequestResult_REGISTERED_SUCCESSFULLY = 0,
  HelloRequestResult_ALREADY_REGISTERED = 1,
  HelloRequestResult_MIN = HelloRequestResult_REGISTERED_SUCCESSFULLY,
  HelloRequestResult_MAX = HelloRequestResult_ALREADY_REGISTERED
};

inline const HelloRequestResult (&EnumValuesHelloRequestResult())[2] {
  static const HelloRequestResult values[] = {
    HelloRequestResult_REGISTERED_SUCCESSFULLY,
    HelloRequestResult_ALREADY_REGISTERED
  };
  return values;
}

inline const char * const *EnumNamesHelloRequestResult() {
  static const char * const names[3] = {
    "REGISTERED_SUCCESSFULLY",
    "ALREADY_REGISTERED",
    nullptr
  };
  return names;
}

inline const char *EnumNameHelloRequestResult(HelloRequestResult e) {
  if (flatbuffers::IsOutRange(e, HelloRequestResult_REGISTERED_SUCCESSFULLY, HelloRequestResult_ALREADY_REGISTERED)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesHelloRequestResult()[index];
}

enum ResponseType : uint8_t {
  ResponseType_NONE = 0,
  ResponseType_HelloResponse = 1,
  ResponseType_GetPeersResponse = 2,
  ResponseType_MIN = ResponseType_NONE,
  ResponseType_MAX = ResponseType_GetPeersResponse
};

inline const ResponseType (&EnumValuesResponseType())[3] {
  static const ResponseType values[] = {
    ResponseType_NONE,
    ResponseType_HelloResponse,
    ResponseType_GetPeersResponse
  };
  return values;
}

inline const char * const *EnumNamesResponseType() {
  static const char * const names[4] = {
    "NONE",
    "HelloResponse",
    "GetPeersResponse",
    nullptr
  };
  return names;
}

inline const char *EnumNameResponseType(ResponseType e) {
  if (flatbuffers::IsOutRange(e, ResponseType_NONE, ResponseType_GetPeersResponse)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesResponseType()[index];
}

template<typename T> struct ResponseTypeTraits {
  static const ResponseType enum_value = ResponseType_NONE;
};

template<> struct ResponseTypeTraits<Seeder::HelloResponse> {
  static const ResponseType enum_value = ResponseType_HelloResponse;
};

template<> struct ResponseTypeTraits<Seeder::GetPeersResponse> {
  static const ResponseType enum_value = ResponseType_GetPeersResponse;
};

bool VerifyResponseType(flatbuffers::Verifier &verifier, const void *obj, ResponseType type);
bool VerifyResponseTypeVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct HelloResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef HelloResponseBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_RESULT = 4,
    VT_AVAILABILITY_INTERVAL = 6
  };
  Seeder::HelloRequestResult result() const {
    return static_cast<Seeder::HelloRequestResult>(GetField<int8_t>(VT_RESULT, 0));
  }
  int8_t availability_interval() const {
    return GetField<int8_t>(VT_AVAILABILITY_INTERVAL, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_RESULT) &&
           VerifyField<int8_t>(verifier, VT_AVAILABILITY_INTERVAL) &&
           verifier.EndTable();
  }
};

struct HelloResponseBuilder {
  typedef HelloResponse Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_result(Seeder::HelloRequestResult result) {
    fbb_.AddElement<int8_t>(HelloResponse::VT_RESULT, static_cast<int8_t>(result), 0);
  }
  void add_availability_interval(int8_t availability_interval) {
    fbb_.AddElement<int8_t>(HelloResponse::VT_AVAILABILITY_INTERVAL, availability_interval, 0);
  }
  explicit HelloResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<HelloResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<HelloResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<HelloResponse> CreateHelloResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    Seeder::HelloRequestResult result = Seeder::HelloRequestResult_REGISTERED_SUCCESSFULLY,
    int8_t availability_interval = 0) {
  HelloResponseBuilder builder_(_fbb);
  builder_.add_availability_interval(availability_interval);
  builder_.add_result(result);
  return builder_.Finish();
}

struct GetPeersResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetPeersResponseBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ACTIVE_PEERS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *active_peers() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_ACTIVE_PEERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ACTIVE_PEERS) &&
           verifier.VerifyVector(active_peers()) &&
           verifier.VerifyVectorOfStrings(active_peers()) &&
           verifier.EndTable();
  }
};

struct GetPeersResponseBuilder {
  typedef GetPeersResponse Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_active_peers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> active_peers) {
    fbb_.AddOffset(GetPeersResponse::VT_ACTIVE_PEERS, active_peers);
  }
  explicit GetPeersResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<GetPeersResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetPeersResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetPeersResponse> CreateGetPeersResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> active_peers = 0) {
  GetPeersResponseBuilder builder_(_fbb);
  builder_.add_active_peers(active_peers);
  return builder_.Finish();
}

inline flatbuffers::Offset<GetPeersResponse> CreateGetPeersResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *active_peers = nullptr) {
  auto active_peers__ = active_peers ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*active_peers) : 0;
  return Seeder::CreateGetPeersResponse(
      _fbb,
      active_peers__);
}

struct Response FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ResponseBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_RESPONSE_TYPE = 6,
    VT_RESPONSE = 8
  };
  uint16_t id() const {
    return GetField<uint16_t>(VT_ID, 0);
  }
  Seeder::ResponseType response_type() const {
    return static_cast<Seeder::ResponseType>(GetField<uint8_t>(VT_RESPONSE_TYPE, 0));
  }
  const void *response() const {
    return GetPointer<const void *>(VT_RESPONSE);
  }
  template<typename T> const T *response_as() const;
  const Seeder::HelloResponse *response_as_HelloResponse() const {
    return response_type() == Seeder::ResponseType_HelloResponse ? static_cast<const Seeder::HelloResponse *>(response()) : nullptr;
  }
  const Seeder::GetPeersResponse *response_as_GetPeersResponse() const {
    return response_type() == Seeder::ResponseType_GetPeersResponse ? static_cast<const Seeder::GetPeersResponse *>(response()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint16_t>(verifier, VT_ID) &&
           VerifyField<uint8_t>(verifier, VT_RESPONSE_TYPE) &&
           VerifyOffset(verifier, VT_RESPONSE) &&
           VerifyResponseType(verifier, response(), response_type()) &&
           verifier.EndTable();
  }
};

template<> inline const Seeder::HelloResponse *Response::response_as<Seeder::HelloResponse>() const {
  return response_as_HelloResponse();
}

template<> inline const Seeder::GetPeersResponse *Response::response_as<Seeder::GetPeersResponse>() const {
  return response_as_GetPeersResponse();
}

struct ResponseBuilder {
  typedef Response Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(uint16_t id) {
    fbb_.AddElement<uint16_t>(Response::VT_ID, id, 0);
  }
  void add_response_type(Seeder::ResponseType response_type) {
    fbb_.AddElement<uint8_t>(Response::VT_RESPONSE_TYPE, static_cast<uint8_t>(response_type), 0);
  }
  void add_response(flatbuffers::Offset<void> response) {
    fbb_.AddOffset(Response::VT_RESPONSE, response);
  }
  explicit ResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Response> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Response>(end);
    return o;
  }
};

inline flatbuffers::Offset<Response> CreateResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t id = 0,
    Seeder::ResponseType response_type = Seeder::ResponseType_NONE,
    flatbuffers::Offset<void> response = 0) {
  ResponseBuilder builder_(_fbb);
  builder_.add_response(response);
  builder_.add_id(id);
  builder_.add_response_type(response_type);
  return builder_.Finish();
}

inline bool VerifyResponseType(flatbuffers::Verifier &verifier, const void *obj, ResponseType type) {
  switch (type) {
    case ResponseType_NONE: {
      return true;
    }
    case ResponseType_HelloResponse: {
      auto ptr = reinterpret_cast<const Seeder::HelloResponse *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ResponseType_GetPeersResponse: {
      auto ptr = reinterpret_cast<const Seeder::GetPeersResponse *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyResponseTypeVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyResponseType(
        verifier,  values->Get(i), types->GetEnum<ResponseType>(i))) {
      return false;
    }
  }
  return true;
}

inline const Seeder::Response *GetResponse(const void *buf) {
  return flatbuffers::GetRoot<Seeder::Response>(buf);
}

inline const Seeder::Response *GetSizePrefixedResponse(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Seeder::Response>(buf);
}

inline bool VerifyResponseBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Seeder::Response>(nullptr);
}

inline bool VerifySizePrefixedResponseBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Seeder::Response>(nullptr);
}

inline void FinishResponseBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Seeder::Response> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedResponseBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Seeder::Response> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Seeder

#endif  // FLATBUFFERS_GENERATED_RESPONSE_SEEDER_H_
