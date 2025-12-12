#ifndef _I2C_PAL_H
#define _I2C_PAL_H

#include <stdint.h>

/* opaque struct, so the actual contents are implementation depedent,
 allowing better portability and no leaking of Platform-related specifics*/
typedef struct i2c_data i2c_handler_t;

namespace pal
{

i2c_handler_t *i2c_init(uint8_t bus);
void i2c_deinit(i2c_handler_t *handler);
bool i2c_probe(const i2c_handler_t *handler, uint8_t address);
int32_t i2c_read(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr);
void i2c_read(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr, uint8_t *output_buffer, uint8_t count);
int32_t i2c_write(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr, uint8_t value);
int32_t i2c_write(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr, uint16_t value);
void i2c_write(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr, uint8_t *input_buffer, uint8_t count);

} //namespace pal

#endif