// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract Bank {
    address private accHolder;
    uint256 private balance = 0;

    constructor() {
        accHolder = msg.sender;
    }

    function withdraw(uint256 _amount) public {
        require(balance > 0,"You don't have enough balance");
        require(_amount > 0,"Enter Amount greater than zero to withdraw");
        require(balance >= _amount, "Insufficient balance");
        require(accHolder == msg.sender,"You are not the Real Account Holder");
        
        balance -= _amount;

        (bool success, ) = payable(msg.sender).call{value:_amount}("");
        require(success,"Transfer failed");
    }

    function deposit() public payable {
        require(msg.value > 0,"Amount should be greater than 0");
        require(accHolder == msg.sender,"You are not the Real Account Holder");
        balance += msg.value;

    }

    function showBalance() public view returns(uint){
        return balance;
    }

}
