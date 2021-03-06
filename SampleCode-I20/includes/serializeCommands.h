#ifndef SERIALIZE_COMMANDS_H
#define SERIALIZE_COMMANDS_H
#include <sharedDefines.h>
#include <sharedSingleOrder.h>
#include <string>
#include <money.h>
//extern "C"
namespace API2 {
  namespace Serialization {

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */

    void serialize(const UNSIGNED_LONG &val, char *buf, int &bytes);

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */

    void serialize(const UNSIGNED_CHARACTER &val, char *buf, int &bytes);

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */

    void serialize(const char &val, char *buf, int &bytes);

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */

    void serialize(const UNSIGNED_INTEGER &val, char *buf, int &bytes);

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */

    void serialize(const int &val, char *buf, int &bytes);


    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */

    void serialize(const UNSIGNED_SHORT &val, char *buf, int &bytes);

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */
    void serialize(const short &val, char *buf, int &bytes);

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */
    void serialize(const SIGNED_LONG &val, char *buf, int &bytes);

    /**
 * @brief serialize will serialize the long value and append to buf and auto-increment bytes with size of data serialized
 * @param val to be serialized
 * @param buf char array pointer
 * @param bytes start index of char, auto adjusted according to size of val after serialization
 */
    void serialize(const std::string &val, char *buf, int &bytes);

    void serialize(const char *val, size_t size,char *buf, int &bytes);

    /**
 * @brief serializeAccountDetails
 * @param accountDetails, to be serialized
 * @param buf
 * @param bytes
 */
    void serialize(const AccountDetail &accountDetails, char* buf, int &bytes);


    /**
     * @brief serialize
     * @param money
     * @param buf
     * @param bytes
     */
    void serialize(const Currency::Money &money, char* buf, int &bytes);

    /**
     * @brief serialize
     * @param data
     * @param buf
     * @param bytes
     */
    void serialize(const StringSet &data, char* buf, int &bytes);


    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(UNSIGNED_LONG &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    //void deSerialize(SIGNED_LONG_LONG &val, const char *buf, int &offset);

     
    /* @brief serialize StringList
     * @param StringList
     * @param buf
     * @param bytes
     */
    void serialize(const StringList &data, char *buf, int &bytes);
    /**
     * @brief deSerialize StringList
     * @param StringList
     * @param buf
     * @param bytes
     */
    void deSerialize(StringList &data, const char *buf, int &offset);


    void deSerialize(UNSIGNED_CHARACTER &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(char &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(UNSIGNED_INTEGER &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(int &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(UNSIGNED_SHORT &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(short &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(SIGNED_LONG &val, const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param val to be deserialized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(std::string &val, const char *buf, int &offset);
    void deSerialize(char *val, size_t size,const char *buf, int &offset);

    /**
 * @brief deSerialize overloaded function, deserializes to val from buf, and adjusts offset to bytes read for deserialization.
 * @param accountDetails to be deseralized
 * @param buf char array pointer
 * @param offset start index of char, auto adjusted according to size of val after deserialization
 */
    void deSerialize(AccountDetail &accountDetails, const char *buf, int &offset);


    /**
     * @brief deSerialize
     * @param money
     * @param buf
     * @param offset
     */
  void deSerialize(Currency::Money &money, const char *buf, int &offset);

    /**
     * @brief deSerialize
     * @param money
     * @param buf
     * @param offset
     */
    void deSerialize(StringSet &data, const char *buf, int &offset);


    /**
     * @brief deSerialize
     * @param money
     * @param buf
     * @param offset
     */
//    void deSerialize(Currency::Money &money, const char *buf, int &offset);

     /* @brief deserializeAccountDetails
 * @param accountDetails
 * @param buf
 * @param offset
 */
    void deserializeAccountDetails(AccountDetail &accountDetails, const char* buf, int &offset);

    /**
 * @brief serializeAccountDetails
 * @param accountDetails
 * @param buf
 * @param bytes
 */
    void serializeAccountDetails(AccountDetail &accountDetails, char* buf, int &bytes);

  }
}
#endif
