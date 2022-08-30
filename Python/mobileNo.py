import phonenumbers as pn
from phonenumbers import carrier,geocoder,timezone

mobileno = input("Enter mobile number with country code")
mobileno = pn.parse(mobileno)

print(timezone.time_zones_for_number(mobileno))
print(carrier.name_for_number(mobileno,'en'))
print(geocoder.description_for_number(mobileno,'en'))

print('Valid mobile number : ',pn.is_valid_number(mobileno))
print("Checking possibility of Number:",pn.is_possible_number(mobileno))

# for i in range(10):
#     print("hi");