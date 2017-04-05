#include "Scoreboard.h"

Scoreboard::Scoreboard() : _level(1), _score(0), _speed(1) 
{
	readHiScore();
	initText();
}

void Scoreboard::draw()
{
	for (std::vector<Letter>::iterator it = _text.begin(); it != _text.end(); ++it)
	{
		it->draw();
	}

	for (std::vector<Letter>::iterator it = _finalMessage.begin(); it != _finalMessage.end(); ++it)
	{
		it->draw();
	}
}

void Scoreboard::initText()
{
	int br = 0;
	double _space;
	
	_text.clear();

	glm::vec3 _position = Settings::TextPosition;
	glm::vec3 _back = glm::vec3(0.0);
	glm::vec3 _up = glm::vec3(0.0);

	std::string text = "Score  \n" + std::to_string(_score) +
		"  \n\nHi-score  \n" + std::to_string(_hiScore) +
		"  \n\nLevel  \n" + std::to_string(_level) +
		"  \n\nSpeed  \n" + std::to_string(_speed) +
		"  \n\n\n\n\n\n" +
 		"Press 'Q' to quit. \nPress 'R' to restart. \nPress 'P' to start/pause. ";

	Letter init(text[text.length() - 1]);
	init.setPosition(_position);
	_text.push_back(init);

	Letter space('_');
	space.setFont(Settings::RegularFont);
	space.setFontSize(Settings::DefaultFontSize);
	_space = 2 * space.getWidth();

	for (int i = text.length() - 2; i >= 0; i--)
	{
		Letter letter(text[i]);

		if (br > 2)
		{
			letter.setFontSize(Settings::BigFontSize);
		}
		if (text[i] >= 48 && text[i] <= 57) 
		{ 
			letter.setFontSize(Settings::BigFontSize); 
			letter.setFont(Settings::BoldFont); 
		}

		if (text[i] == '\n')
		{
			br++;
			_up += glm::vec3(0.0, 1.2*letter.getHeight(), 0.0);
		}
		else
		{
			if (text[i + 1] != '\n')
			{
				if (text[i + 1] == ' ')
				{
					letter.setPosition(_text.back().getPosition() - glm::vec3(_space, 0.0, 0.0));
					_back += glm::vec3(_space, 0.0, 0.0);
				}
				else
				{
					letter.setPosition(_text.back().getPosition() - glm::vec3(1.2*letter.getWidth(), 0.0, 0.0));
					_back += glm::vec3(1.2*letter.getWidth(), 0.0, 0.0);
				}
			}
			else
			{
				letter.setPosition(_text.back().getPosition() + _back + _up);
				_back = glm::vec3(0.0);
				_up = glm::vec3(0.0);
			}
			
			_text.push_back(letter);
		}
	}
}

void Scoreboard::initFinalMessage()
{
	float _width = 0;
	glm::vec3 position = Settings::FinalMessagePosition;

	std::string finalMessage;

	if (_score < 10 * _level * Settings::SnakeMagnitude - 10)
	{
		finalMessage = "GAME OVER!";
	}
	else
	{
		finalMessage = "YOU WIN!";
	}


	_finalMessage.clear();

	for (unsigned int i = 0; i < finalMessage.length(); i++)
	{
		_finalMessage.push_back(Letter(finalMessage[i]));
		_finalMessage.back().setFontSize(Settings::BigFontSize);
		_finalMessage.back().setFont(Settings::BoldFont);

		_finalMessage.back().setPosition(position + glm::vec3(1.1 * _width, 0.0, 0.0));

		if (finalMessage[i] == ' ')
		{
			_finalMessage.back().setPosition(position + glm::vec3(2 * _width, 0.0, 0.0));
		}

		position = _finalMessage.back().getPosition();
		_width = _finalMessage.back().getWidth();
	}
}

void Scoreboard::clearFinalMessage()
{
	_finalMessage.clear();
}

void Scoreboard::updateScore()
{
	_score += 10;
	if (_hiScore < _score)
	{
		_hiScore = _score;
	}
	initText();
}

const int Scoreboard::getScore() const
{
	return _score;
}

void Scoreboard::setScore(unsigned short score)
{
	_score = score;
	initText();
}

void Scoreboard::readHiScore()
{
	std::string hiScore;
	std::ifstream infile;
	infile.open(Settings::HiScoreFilePath, std::ifstream::in);
	std::getline(infile, hiScore);
	infile.close();

	_hiScore = std::atoi(hiScore.c_str());
}

void Scoreboard::writeHiScore()
{
	std::ofstream outfile;
	outfile.open(Settings::HiScoreFilePath, std::ofstream::out);
	outfile.write(std::to_string(_hiScore).c_str(), std::to_string(_hiScore).size());
	outfile.close();
}

const int Scoreboard::getHiScore() const
{
	return _hiScore;
}

void Scoreboard::setHiScore(unsigned short score)
{
	_hiScore = score;
	initText();
}

void Scoreboard::setSpeed(unsigned short speed)
{
	_speed = speed;
	initText();
}

const int Scoreboard::getSpeed() const
{
	return _speed;
}

const int Scoreboard::getLevel() const
{
	return _level;
}

void Scoreboard::setLevel(unsigned short level)
{
	_level = level;
	initText();
}