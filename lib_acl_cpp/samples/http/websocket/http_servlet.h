#pragma once

class http_servlet : public acl::HttpServlet
{
public:
	http_servlet(acl::redis_client_cluster& cluster, size_t max_conns);
	~http_servlet();

	acl::session& get_session() const
	{
		return *session_;
	}

protected:
	// @override
	bool doUnknown(acl::HttpServletRequest&, acl::HttpServletResponse&);

	// @override
	bool doGet(acl::HttpServletRequest&, acl::HttpServletResponse&);

	// @override
	bool doPost(acl::HttpServletRequest&, acl::HttpServletResponse&);

	// @override
	bool doWebsocket(acl::HttpServletRequest&, acl::HttpServletResponse&);

private:
	acl::session* session_;

	bool doPing(acl::websocket&, acl::websocket&);
	bool doPong(acl::websocket&, acl::websocket&);
	bool doClose(acl::websocket&, acl::websocket&);
	bool doMsg(acl::websocket&, acl::websocket&);
};