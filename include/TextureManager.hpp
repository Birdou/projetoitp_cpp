
#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SDL2/SDL.h>

struct TextureManager
{
	/**
	 * @brief      Loads a texture.
	 *
	 * @param[in]  fileName  The file name
	 *
	 * @return     { description_of_the_return_value }
	 */
	static SDL_Texture* LoadTexture(const char * fileName);
	/**
	 * @brief      { function_description }
	 *
	 * @param      tex   The tex
	 */
	static void Draw(SDL_Texture* tex);
	/**
	 * @brief      { function_description }
	 *
	 * @param      tex   The tex
	 * @param[in]  dest  The destination
	 */
	static void Draw(SDL_Texture* tex, const SDL_Rect& dest);
	/**
	 * @brief      { function_description }
	 *
	 * @param      tex   The tex
	 * @param[in]  src   The source
	 * @param[in]  dest  The destination
	 */
	static void Draw(SDL_Texture* tex, const SDL_Rect& src, const SDL_Rect& dest);
	/**
	 * @brief      { function_description }
	 *
	 * @param      tex   The tex
	 * @param[in]  src   The source
	 * @param[in]  dest  The destination
	 * @param[in]  ang   The angle
	 * @param[in]  flip  The flip
	 */
	static void Draw(SDL_Texture* tex, const SDL_Rect& src, const SDL_Rect& dest, float ang, SDL_RendererFlip flip);
};

#endif