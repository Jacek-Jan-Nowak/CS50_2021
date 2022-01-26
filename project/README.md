# Dress to Impress
#### Video Demo:  <https://youtu.be/DG_s9T73ero>
#### Description:
An app to help you lend or borrow a dress for any occasion.

It helps people, who always have a problem with what to wear. Instead of buying a new outfit every time you can just rent it for a fraction of the cost. Furthermore, this solution is much more sustainable, generating much less waste.

The app was written with use of Ruby on Rails in a traditional MVC pattern.

#### User journey:

- Firstly, the user has to set up an account. Only the homepage and /dresses pages are available without being logged in. To do that, the user has to come up with a username, write their email and set up a password. Optionally, the user can add their avatar picture.

- Then, the user can either book or lend dresses to other users.

- To book a dress, user is redirected to /dresses page, where there is a list view of dresses as well as a map view. There, they can see basic information on the dress and be redirected to the more detailed page.

- On the individual dress page, the user can see more details about a dress, including its brand, size a description and reviews by other users. They can also book a dress for a certain date.

- If a user wants to lend a dress they have to open the menu (clck on their avatar) and then go to /my-dresses. There, they can add a dress and include basic information on the size, brand and collection address.

- Users can manage their bookings through /my-bookings in the main menu.

- Lenders can manage the booking requests through /booking-requests and manage dresses through /my-dresses in the main menu.

#### Database:

It has 3 models - users, dresses and reviews:

- users table has columns such as username, password, email and avatar picture.

- dresses table has columns such as user_id, title, description, brand, size, address (for collection purposes).

- reviews table contains user_id, title, description and rating.

#### Gems:

A gem called 'devise' was used to manage users model. For dresses and reviews models all CRUD actions were coded.

Other gems that were used were faker, dotenv-rails, geocoder and cloudinary.

#### Other integrations:

The application was hosted on Heroku with use of active storage and Cloudinary, where all the images are being stored.
The front-end side was coded with use of standard HTML, CSS, JavaScript and Bootstrap.

On the /dresses page, there is a map that is integrated through JavaScript and uses Mapbox API.

The biggest challenges in this project were implementing a confirm / reject a booking actions.

There are still elements that could be implemented, such as display of current bookings or checking that the dress is not overbooked, that it isn't being rented at the same time by two users. A calendar could also be implemented for an easier booking process.


#### Stack:

The back end of the application was written with Ruby and Ruby on Rails.

The front end of the application was written with HTML, CSS, JavaScript.

The application was hosted on Heroku cloud service.

To see the website live please visit the link below.

[>>> Click for the live website <<<](https://dress-2-impress.herokuapp.com/)


### Thank you for your time! We hope you enjoyed!

Patrycja Miekina & Jacek Nowak