-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jun 26, 2014 at 12:38 PM
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
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'SKorea', 'CalculatorTest::cublic', '2014-06-25 11:10:49'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'SKorea', 'CalculatorTest::cublic [ Success ]', '2014-06-25 11:17:15'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]', '2014-06-25 11:17:42'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:19:41'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:20:24'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:20:27'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:21:05'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:30:26'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:30:27'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:30:27'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:30:28'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:30:28'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ] CalculatorTest::multiply [ Failed ] Value of: c2.multiply(10,35)   Actual: 350 Expected: 1000.00 Which is: 1000 ', '2014-06-25 11:30:29'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 12:37:06'),
('gokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 12:37:39'),
('kagokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 12:37:42'),
('kagokul@gmail.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 12:38:30'),
('kartha.gokul@yahoo.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 13:55:39'),
('kartha.gokul@yahoo.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 14:01:39'),
('kartha.gokul@yahoo.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 14:01:40'),
('kartha.gokul@yahoo.com', '00:0C:29:54:42:12', 50, 'South Korea', 'CalculatorTest::cublic [ Success ]\nCalculatorTest::multiply [ Failed ]\nValue of: c2.multiply(10,35)\n  Actual: 350\nExpected: 1000.00\nWhich is: 1000\n', '2014-06-25 14:01:40'),
('kartha.gokul@yahoo.com', '10:09:3D:12:33:33', 100, 'korea', 'hello', '2014-06-26 11:29:23');

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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `first_name`, `last_name`, `email`) VALUES
(1, 'kartha.gokul@yahoo.com', 'gokul123', 'Gokul', 'Kartha', 'kartha.gokul@yahoo.com'),
(2, 'everyourgokul@gmail.com', 'gokul123', '', '', ''),
(3, 'everyourgokul1@gmail.com', '', 'go', 'ff', 'everyourgokul@gmail.com'),
(4, '1everyourgokul1@gmail.com', '', 'go', 'ff', '1everyourgokul1@gmail.com'),
(5, 'admin', 'admin', 'Admin', 'Admin', 'admin@system.com');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
