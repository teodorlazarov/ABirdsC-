#include "Sprite.h"

const float M2P = 100;
const float P2M = 1 / M2P;
const float DEGTORAD = 0.0174532925199432957f;
const float RADTODEG = 57.295779513082320876f;

Sprite::Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h)
{
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

	if (image == NULL)
	{
		std::cout << "Couldn't Load " << FilePath.c_str() << std::endl;
	}

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &image_width, &image_height);

	crop.x = 0;
	crop.y = 0;
	crop.w = image_width;
	crop.h = image_height;

	currentframe = 0;
	Frame_Amount_X = 0;
	Frame_Amount_Y = 0;
}

Sprite::Sprite(SDL_Renderer * passed_renderer, std::string FilePath, int x, int y, int w, int h, int framesX, int framesY)
{
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

	if (image == NULL)
	{
		std::cout << "Couldn't Load " << FilePath.c_str() << std::endl;
	}

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &image_width, &image_height);

	crop.x = 0;
	crop.y = 0;
	crop.w = image_width;
	crop.h = image_height;

	currentframe = 0;
	Frame_Amount_X = framesX;
	Frame_Amount_Y = framesY;
}

Sprite::~Sprite(void)
{
	SDL_DestroyTexture(image);
}

void Sprite::Draw()
{
	SDL_RenderCopy(renderer, image, NULL, &rect);
}

void Sprite::Draw(int x, int y)
{
	rect.x = x;
	rect.y = y;
	SDL_RenderCopy(renderer, image, NULL, &rect);
}

void Sprite::Draw(b2Vec2 newPos)
{
	SDL_Rect temp;
	temp.x = newPos.x * 100;
	temp.y = newPos.y * 100;
	temp.w = rect.w * 2;
	temp.h = rect.h * 2;
	SDL_RenderCopy(renderer, image, NULL, &temp);
}

void Sprite::Draw(b2Vec2 newPos, float angle)
{
	SDL_Rect temp;
	temp.x = newPos.x * M2P;
	temp.y = newPos.y * M2P;
	temp.w = rect.w * 2;
	temp.h = rect.h * 2;
	SDL_RenderCopyEx(renderer, image, NULL, &temp, angle, NULL, SDL_FLIP_NONE);
}

void Sprite::DrawAnimation(b2Vec2 newPos, float angle)
{
	SDL_Rect temp;
	temp.x = newPos.x * M2P;
	temp.y = newPos.y * M2P;
	temp.w = rect.w * 2;
	temp.h = rect.h * 2;
	SDL_RenderCopyEx(renderer, image, &crop, &temp, angle, NULL, SDL_FLIP_NONE);
}

void Sprite::PlayAnimation(int BeginFrame, int EndFrame, float Speed)
{

	if (animationdelay + Speed <SDL_GetTicks())
	{
		if (EndFrame <= currentframe) {
			currentframe = BeginFrame;
		}
		else {
			currentframe++;
		}
		crop.x = currentframe * (image_width / Frame_Amount_X);
		crop.w = image_width / Frame_Amount_X;
		crop.h = image_height / Frame_Amount_Y;

		animationdelay = SDL_GetTicks();
	}

}

void Sprite::DrawSling(b2Vec2 birdPos, b2Vec2 slingPos, double angle)
{
	double distanceBetween = sqrt(pow((slingPos.x - birdPos.x), 2) + pow((slingPos.y - birdPos.y), 2));
	double angle2 = angle;

	rect.w = (distanceBetween * M2P) / 2;

	SDL_Point rotatePoint;
	rotatePoint.x = slingPos.x;
	rotatePoint.y = slingPos.y;

	SDL_Rect temp1;
	temp1.x = (slingPos.x)  * M2P;
	temp1.y = (slingPos.y - 0.1f) * M2P;
	temp1.w = rect.w * 2;
	temp1.h = rect.h * 2;
	angle2 -= 4;
	SDL_RenderCopyEx(renderer, image, NULL, &temp1, angle2, &rotatePoint, SDL_FLIP_NONE);
}



