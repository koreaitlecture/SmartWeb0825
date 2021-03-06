DROP TABLE CUSTOMER;
DROP TABLE BANK;


-- 은행(BANK)
CREATE TABLE BANK(
    BANK_CODE   VARCHAR2(20),
    BANK_NAME   VARCHAR2(30));


-- 고객(CUSTOMER)
CREATE TABLE CUSTOMER(
    NO          NUMBER,
    NAME        VARCHAR2(30)    NOT NULL,
    PHONE       VARCHAR2(30)    UNIQUE,
    AGE         NUMBER(3)       CHECK(AGE >= 0 AND AGE <= 100),  -- CHECK(AGE BETWEEN 0 AND 100)
    GRADE       VARCHAR2(10)    CHECK(GRADE = 'VIP' OR GRADE = 'GOLD'),  -- CHECK(GRADE IN('VIP', 'GOLD'))
    BANK_CODE   VARCHAR2(20));


-- ALTER TABLE(테이블 수정)

-- 1. BANK 테이블에 BANK_PHONE 칼럼을 추가한다.
ALTER TABLE BANK ADD BANK_PHONE VARCHAR2(20);

-- 2. BANK 테이블의 BANK_NAME 칼럼의 타입을 VARCHAR2(10)으로 수정한다.
ALTER TABLE BANK MODIFY BANK_NAME VARCHAR2(10);

-- 3. BANK 테이블의 BANK_NAME 칼럼을 NOT NULL 처리한다.
ALTER TABLE BANK MODIFY BANK_NAME VARCHAR2(10) NOT NULL;

-- 4. CUSTOMER 테이블의 NAME 칼럼을 NULL 처리한다.
ALTER TABLE CUSTOMER MODIFY NAME VARCHAR2(30) NULL;

-- 5. CUSTOMER 테이블의 NAME 칼럼 이름을 CUSTOMER_NAME으로 수정한다.
ALTER TABLE CUSTOMER RENAME COLUMN NAME TO CUSTOMER_NAME;

-- 6. CUSTOMER 테이블의 AGE 칼럼을 삭제한다.
ALTER TABLE CUSTOMER DROP COLUMN AGE;


DESC BANK;
DESC CUSTOMER;


-- 기본키, 외래키
ALTER TABLE BANK ADD CONSTRAINT BANK_PK PRIMARY KEY(BANK_CODE);
ALTER TABLE CUSTOMER ADD CONSTRAINT CUSTOMER_PK PRIMARY KEY(NO);
ALTER TABLE CUSTOMER ADD CONSTRAINT CUSTOMER_BANK_FK FOREIGN KEY(BANK_CODE) REFERENCES BANK(BANK_CODE);
