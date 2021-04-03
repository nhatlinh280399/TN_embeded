#include<PCA9685_Device_Driver.h>

static struct i2c_adapter *PCA9685_i2c_adapter   = NULL;   // I2C Adapter Structure
static struct i2c_client  *PCA9685_i2c_client    = NULL;   // I2C Cient Structure (PCA9685)

/*
** Ham nay write data vao I2C client
** 
** Argument:
**    buff -> buffer to be sent
**    len  -> length of the data
*/
static int I2C_Write(unsigned char *buf, unsigned int len)
{
    /*
    ** Sending Start condition, Slave address with R/W bit, 
    ** ACK/NACK and Stop condtions will be handled internally.
    */ 
    int ret = i2c_master_send(PCA9685_i2c_client, buf, len);
    
    return ret; // Tra ve -1 neu loi,neu khong thi tra ve so byte duoc viet.
}

/*
** Ham nay doc 1 byte data tu I2C client
**
**  Arguments:
**      out_buff -> buffer wherer the data to be copied
**      len      -> Length of the data to be read
** 
*/
static int I2C_Read(unsigned char *out_buf, unsigned int len)
{
    /*
    ** Sending Start condition, Slave address with R/W bit, 
    ** ACK/NACK and Stop condtions will be handled internally.
    */ 
    int ret = i2c_master_recv(PCA9685_i2c_client, out_buf, len);
    
    return ret; // Tra ve -1 neu loi, ney khong thi hoac tra ve so byte da doc 
}


// Ham nay duoc goi khi Slave duoc tim thay
// Chu y: Chi duoc goi duy nhat mot lan khi load driver.

static int PCA9685_probe(struct i2c_client *client,
                         const struct i2c_device_id *id)
{
    
    return 0;
}

// Ham nay duoc goi khi salve bi remove
// Chu y: Chi duoc goi duy nhat mot lan khi unload driver.
static int PCA9685_remove(struct i2c_client *client)
{   
    
    return 0;
}


static void PCA9685_Set_Rotation_Angle(UBYTE channel, UBYTE Angle)
{
	UWORD temp;
	if(Angle < 0 && Angle > 180){
		pr_info("Angle out of range")
	}
}

// I2C Board Info structure

static struct i2c_board_info PCA9685_i2c_board_info = {
	I2C_BOARD_INFO(SLAVE_DEVICE_NAME, PCA9685_SLAVE_ADDR)
};

// Struct chua salve ID

static const struct i2c_device_id PCA9685_id[] = {
	{ SLAVE_DEVICE_NAME, 0},
	{ }
};
MODULE_DEVICE_TABLE(i2c, PCA9685_id);

// I2C driver Structure can add vao linux

static struct i2c_driver PCA9685_driver = {
	.driver = {
		.name   = SLAVE_DEVICE_NAME,
		.owner  = THIS_MODULE,
	},
	.probe         = PCA9685_probe,
	.remove        = PCA9685_remove,
	.id_table      = PCA9685_id,
};



// Module Init function

static int __init PCA9685_driver_init(void)
{
	int ret = -1;
	PCA9685_i2c_adapter = i2c_get_adapter(I2C_BUS_AVAILABLE);

	if(PCA9685_i2c_adapter != NULL)
	{
		PCA9685_i2c_client  = i2c_new_device(PCA9685_i2c_adapter, &PCA9685_i2c_board_info);

		if(PCA9685_i2c_client != NULL)
		{
			i2c_add_driver(&PCA9685_driver);
			ret = 0;
		}

		i2c_put_adapter(PCA9685_i2c_adapter);
	}	

	pr_info("Driver Added!!!\n");
	return ret;
} 

// Module Exit function

static void __exit PCA9685_driver_exit(void)
{
	i2c_unregister_device(PCA9685_i2c_client);
	i2c_del_driver(&PCA9685_driver);
	pr_info("Driver Removed!!!\n");
}

module_init(PCA9685_driver_init);
module_exit(PCA9685_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LAB411 <lab411@sis.hust.edu.vn>");
MODULE_DESCRIPTION("I2C driver PCA9685");
MODULE_VERSION("1.34");