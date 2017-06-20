# 学生信息管理系统，学生数据库（stu）
## 学生信息表（information）
| field | type | null | key |
--------|------|------|-----|
| sno | int(10) | no | pri |
| sname | char(10) | no |
| address | char(10) | yes |
| age | int(2) | yes |
| sex | char(2) | yes |
| scno | int(10) | yes | mul |


## 学校表（school）
| field | type | null | key |
--------|------|------|-----|
| scno | int(10) | no | pri |
| sname | char(20) | no |
| dean | char(10) | yes |

## 课程表(course)
| field | type | null | key |
--------|------|------|-----|
| cno | int(4) | no | pri |
| cname | char(10) | no |

## 成绩表(score)
| field | type | null | key |
--------|------|------|-----|
| sno | int(10) | no | pri |
| cno | int(4) | no | pri |
| mark | int(4) | yes |
