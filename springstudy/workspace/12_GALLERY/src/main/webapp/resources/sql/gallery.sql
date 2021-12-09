CREATE TABLE GALLERY
(
    NO NUMBER PRIMARY KEY,
    WRITER VARCHAR2(100),
    TITLE VARCHAR2(100),
    CONTENT VARCHAR2(100),
    IP VARCHAR2(40),
    ORIGIN VARCHAR2(300),
    SAVED VARCHAR2(300),
    CREATED DATE,
    LASTMODIFIED DATE
);
CREATE SEQUENCE GALLERY_SEQ NOCACHE;