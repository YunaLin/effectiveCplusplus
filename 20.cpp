// 条款20:避免public接口出现数据成员
// 通过get和set函数来操作数据成员而不是将数据成员放在public里面
// 有利于一致性和精确的访问控制
class AccessLevels {
    private:
        int noAccess;
        int readOnly;
        int writeOnly;
        int readWrite;
    public:
        int getReadOnly() const {
            return readOnly;
        }
        void setReadWrite(int value) {
            readWrite = value;
        }
        int getReadWrite() const {
            return readWrite;
        }
        void setWriteOnly(int value) {
            writeOnly = value;
        }
};