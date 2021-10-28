<%@page import="java.text.SimpleDateFormat"%>
<%@page import="java.util.Date"%>
<%@page import="java.util.Optional"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<%-- 디폴트 : 민경태, 44 --%>
	<%
		request.setCharacterEncoding("UTF-8");
		
		Optional<String> optName = Optional.ofNullable(request.getParameter("name"));
		String name = optName.orElse("민경태");
		Optional<String> optAge = Optional.ofNullable(request.getParameter("age"));
		int age = Integer.parseInt(optAge.orElse("44"));
	%>
	<h1>이름 : <%=name%></h1>
	<h1>나이 : <%=age%></h1>
	<input type="button" value="뒤로가기" onclick="history.back()">

	<hr>
	
	<%
		String cmd = request.getParameter("cmd");
		if (cmd == null || cmd.isEmpty()) {
			cmd = "date";
		}
		Date now = new Date();
		SimpleDateFormat sdf1 = new SimpleDateFormat("yyyy-MM-dd");
		SimpleDateFormat sdf2 = new SimpleDateFormat("a hh:mm:ss");
		String result = null;
		switch (cmd) {
		case "date": result = sdf1.format(now); break;
		case "time": result = sdf2.format(now); break;
		}
	%>
	<h1>요청 결과는 <%=result%>입니다.</h1>
	
</body>
</html>
