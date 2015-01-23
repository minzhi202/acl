#pragma once
#include "acl_cpp/acl_cpp_define.hpp"
#include "acl_cpp/redis/redis_command.hpp"

namespace acl
{

class redis_client;
class redis_result;
class string;

class ACL_CPP_API redis_pubsub : public redis_command
{
public:
	redis_pubsub(redis_client* conn = NULL);
	~redis_pubsub();

	/////////////////////////////////////////////////////////////////////

	/**
	 *
	 * @return {int} �ɹ����������ĸ�Ƶ���Ķ���������
	 *  -1����ʾ����
	 *  0��û�ж�����
	 *  > 0�����ĸ�Ƶ���Ķ���������
	 */
	int publish(const char* channel, const char* msg, size_t len);
	int subscribe(const char* first_channel, ...);
	int subscribe(const std::vector<string>& channels);
	int unsubscribe(const char* first_channel, ...);
	int unsubscribe(const std::vector<string>& channels);
	bool get_message(string& channel, string& msg);

private:
	int subop(const char* cmd, const std::vector<string>& channels);
	int check_channel(const redis_result* obj, const char* cmd,
		const string& channel);
};

} // namespace acl