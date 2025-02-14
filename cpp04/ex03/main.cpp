#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	ICharacter *bill = bob;
	bill->equip(src->createMateria("ice"));
	bill->equip(src->createMateria("ice"));
	bill->equip(src->createMateria("ice"));
	bill->equip(src->createMateria("ice"));
	bill->equip(src->createMateria("ice"));
	Character billbob("billbob");
	billbob.equip(src->createMateria("cure"));
	Character bobbill("bobbill");
	bobbill.equip(src->createMateria("ice"));
	bobbill = billbob;
	bobbill.use(0, billbob);
	bobbill.equip(src->createMateria("ice"));
	bobbill.equip(src->createMateria("cure"));
	bobbill.equip(src->createMateria("ice"));
	bobbill.equip(src->createMateria("cure"));
	bobbill.equip(src->createMateria("ice"));
	bobbill.use(2, *bill);
	me->unequip(0);
	me->unequip(3);
	me->use(3, *bob);
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	bob->equip(src->createMateria("cure"));
	bob->equip(src->createMateria("cure"));
	bob->use(0, *me);
	me->use(3, billbob);
	me->unequip(3);
	delete bob;
	delete me;
	delete src;
}
