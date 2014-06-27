-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jun 27, 2014 at 11:34 AM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `gtest_cloud`
--

-- --------------------------------------------------------

--
-- Table structure for table `test_data`
--

CREATE TABLE IF NOT EXISTS `test_data` (
  `userid` varchar(6000) NOT NULL,
  `machineid` varchar(6000) NOT NULL,
  `successrate` int(11) NOT NULL,
  `country` varchar(6000) NOT NULL,
  `details` text NOT NULL,
  `update_date` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `test_data`
--

INSERT INTO `test_data` (`userid`, `machineid`, `successrate`, `country`, `details`, `update_date`) VALUES
('kartha.gokul', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-27 11:30:02'),
('kartha.gokul', '10:09:3D:12:33:33', 100, 'korea', 'test_from_browser', '2014-06-27 11:30:54'),
('kartha.gokul', '10:09:3D:12:33:33', 70, 'korea', 'test_from_browser', '2014-06-27 11:31:03'),
('kartha.gokul', '10:09:3D:12:33:33', 98, 'korea', 'test_from_browser', '2014-06-27 11:31:12'),
('kartha.gokul', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-27 11:32:30'),
('kartha.gokul', '10:09:3D:12:33:33', 98, 'korea', 'test_from_browser', '2014-06-27 11:32:37');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `first_name` varchar(255) NOT NULL,
  `last_name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `first_name`, `last_name`, `email`) VALUES
(6, 'admin', 'admin', 'Admin', 'GTest', 'admin@gtest.com'),
(7, 'kartha.gokul', 'gokul123', 'Gokul', 'Kartha', 'kartha.gokul@gmail.com');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
