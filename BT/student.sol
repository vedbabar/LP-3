// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StudentData {

    struct Student {
        uint256 rollNo;
        string name;
        uint256 marks;
    }

    Student[] public students;

    function addStudent(uint256 _rollNo, string memory _name, uint256 _marks) public {
        students.push(Student(_rollNo, _name, _marks));
    }

    function getStudent(uint256 _index) public view returns (uint256, string memory, uint256) {
        Student memory s = students[_index];
        return (s.rollNo, s.name, s.marks);
    }

    function getCount() public view returns (uint256) {
        return students.length;
    }
}
